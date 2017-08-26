#include <iostream>
#include <fstream>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h>

#include <CGAL/boost/graph/graph_traits_Polyhedron_3.h>
#include <CGAL/VSA_approximation.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::FT FT;
typedef CGAL::Polyhedron_3<Kernel> Polyhedron;
typedef boost::property_map<Polyhedron, boost::vertex_point_t>::type VertexPointMap;

typedef CGAL::L21Metric<Polyhedron> L21Metric;
typedef CGAL::L21ProxyFitting<Polyhedron> L21ProxyFitting;
typedef CGAL::VSA_approximation<Polyhedron, VertexPointMap> VSAL21;

bool check_strict_ordering(const std::vector<FT> &error)
{
  if (error.empty()) {
    std::cout << "Empty error sequence." << std::endl;
    return false;
  }
  FT pre = error.front();
  for (std::vector<FT>::const_iterator itr = error.begin(); itr != error.end(); ++itr)
    if (pre < *itr)
      return false;

  return true;
}

/**
 * This file tests the decrease of the relaxing error on a sphere shape.
 */
int main()
{
  Polyhedron mesh;
  std::ifstream input("./data/sphere_iso.off");
  if (!input || !(input >> mesh) || mesh.empty()) {
    std::cerr << "Invalid off file." << std::endl;
    return EXIT_FAILURE;
  }

  // algorithm instance
  VSAL21 vsa_l21(mesh,
    get(boost::vertex_point, const_cast<Polyhedron &>(mesh)));

  L21Metric l21_metric(mesh);
  L21ProxyFitting l21_fitting(mesh);
  vsa_l21.set_metric(l21_metric, l21_fitting);

  vsa_l21.init_proxies(100, VSAL21::RandomInit);
  std::vector<FT> error;
  for (std::size_t i = 0; i < 30; ++i)
    error.push_back(vsa_l21.run_one_step());

  if (check_strict_ordering(error)) {
    std::cout << "Pass the decrease test." << std::endl;
    return EXIT_SUCCESS;
  }
  else {
    std::cout << "Failed the decrease test." << std::endl;
    return EXIT_FAILURE;
  }
}
