// Copyright (c) 2003,2004,2005,2006  INRIA Sophia-Antipolis (France) and
// Notre Dame University (U.S.A.).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Segment_Delaunay_graph_Linf_2/include/CGAL/Segment_Delaunay_graph_Linf_2/Traits_base_2.h $
// $Id: Traits_base_2.h 56667 2010-06-09 07:37:13Z sloriot $
//
// Author(s)     : Menelaos Karavelas <mkaravel@cse.nd.edu>

#ifndef CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_TRAITS_BASE_2_H
#define CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_TRAITS_BASE_2_H

#include <CGAL/Segment_Delaunay_graph_Linf_2/basic.h>
#include <CGAL/Segment_Delaunay_graph_Linf_2/Predicates_C2.h>
#include <CGAL/Segment_Delaunay_graph_Linf_2/Constructions_C2.h>
#include <CGAL/Segment_Delaunay_graph_Linf_2/Kernel_wrapper_2.h>

namespace CGAL {

/*namespace Internal {

  template<class K,class BooleanTag> struct Which_arrangement_type;

  // Tag_true means that we want to support intersections
  template<class K>
  struct Which_arrangement_type<K,Tag_true>
  {
    typedef
    CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Arrangement_type_C2<K>
    Arrangement_type;
  };

  // Tag_false means that we do not want to support intersections
  template<class K>
  struct Which_arrangement_type<K,Tag_false>
  {
    typedef
    CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Arrangement_type_non_intersecting_C2<K>
    Arrangement_type;
  };

} // namespace Internal*/


//-----------------------------------------------------------------------
// the Traits class
//-----------------------------------------------------------------------

template<class R, class MTag, class ITag>
class Segment_Delaunay_graph_Linf_traits_base_2
{
public:
  //-----------------------------------------------------------------------
  //                  TYPE DEFINITIONS
  //-----------------------------------------------------------------------

  // BASIC TYPES
  //------------
  
  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Kernel_wrapper_2<R,ITag>  Kernel;
  typedef Kernel                                              K;
  typedef R                                                   Rep;
  typedef MTag                                                Method_tag;

  // the following tag controls how support intersections in the
  // traits. If it is Tag_true then we fully support intersections.
  // If it is Tag_true it is assumed that no intersections appear in
  // the data and so there is limited support for intersections.
  typedef ITag                                    Intersections_tag;

  typedef typename Kernel::Point_2                Point_2;
  typedef typename Kernel::Line_2                 Line_2;
  typedef typename Kernel::Segment_2              Segment_2;
  typedef typename Kernel::Ray_2                  Ray_2;
  typedef typename Kernel::Iso_rectangle_2        Iso_rectangle_2;
  typedef typename Kernel::Direction_2            Direction_2;
  typedef typename Kernel::Vector_2               Vector_2;
  //  typedef typename Kernel::Circle_2               Circle_2;

  typedef typename Kernel::Site_2                 Site_2;
  typedef typename Kernel::Object_2               Object_2;

  typedef typename Kernel::FT                     FT;
  typedef typename Kernel::RT                     RT;

  typedef typename Kernel::Sign                   Sign;

protected:
  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Internal::Arrangement_enum
  Arrangement_enum;

public:
  // OBJECT CONSTRUCTION & ASSIGNMENT
  //-------------------------------
  typedef typename Kernel::Construct_object_2     Construct_object_2;
  typedef typename Kernel::Assign_2               Assign_2;

  // CONSTRUCTIONS
  //--------------
  // vertex, bisector, and Voronoi circle
  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Construct_svd_vertex_2<K,MTag>
  Construct_svd_vertex_2;

  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Construct_sdg_bisector_2<K,MTag>
  Construct_sdg_bisector_2;

  /*
  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Construct_svd_circle_2<K,MTag>
  Construct_svd_circle_2;
  */

  // PREDICATES
  //-----------
  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Compare_x_2<K>
  Compare_x_2;

  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Compare_y_2<K>
  Compare_y_2;

  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Orientation_L2_C2<K>
  Orientation_L2_2;

  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Orientation_Linf_C2<K>
  Orientation_Linf_2;

  // used by triangulation 
  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Orientation_Linf_C2<K>
  Orientation_2;

  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Are_same_points_C2<K>
  Equal_2;

  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Are_parallel_C2<K>
  Are_parallel_2;

  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Oriented_side_of_bisector_C2<K,MTag>
  Oriented_side_of_bisector_2;

  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Vertex_conflict_C2<K,MTag>
  Vertex_conflict_2;

  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Finite_edge_interior_conflict_C2<K,MTag>
  Finite_edge_interior_conflict_2;

  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Infinite_edge_interior_conflict_C2<K,MTag>
  Infinite_edge_interior_conflict_2;

  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Is_degenerate_edge_C2<K,MTag>
  Is_degenerate_edge_2;

#ifdef CGAL_SDG_USE_SIMPLIFIED_ARRANGEMENT_TYPE_PREDICATE
  typedef typename
  Internal::Which_arrangement_type<K,ITag>::Arrangement_type
  Arrangement_type_2;
#else
  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Arrangement_type_C2<K>
  Arrangement_type_2;
#endif

  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_NS::Oriented_side_C2<K,MTag>
  Oriented_side_2;

public:
  //-----------------------------------------------------------------------
  //                  ACCESS TO OBJECTS
  //-----------------------------------------------------------------------

  // OBJECT CONSTRUCTION & ASSIGNMENT
  //---------------------------------
  Assign_2
  assign_2_object() const {
    return Assign_2();
  }

  Construct_object_2
  construct_object_2_object() const { 
    return Construct_object_2();
  }

  // CONSTRUCTIONS
  //--------------
  Construct_svd_vertex_2
  construct_svd_vertex_2_object() const { 
    return Construct_svd_vertex_2();
  }

  Construct_sdg_bisector_2
  construct_sdg_bisector_2_object() const { 
    return Construct_sdg_bisector_2();
  }

  /*
  Construct_svd_circle_2
  construct_svd_circle_2_object() const {
    return Construct_svd_circle_2();
  }
  */

  // PREDICATES
  //-----------
  Compare_x_2
  compare_x_2_object() const {
    return Compare_x_2();
  }

  Compare_y_2
  compare_y_2_object() const {
    return Compare_y_2();
  }

  Orientation_L2_2
  orientation_L2_2_object() const {
    return Orientation_L2_2();
  }

  Orientation_Linf_2
  orientation_Linf_2_object() const {
    return Orientation_Linf_2();
  }

  Orientation_2
  orientation_2_object() const {
    return Orientation_2();
  }

  Equal_2
  equal_2_object() const {
    return Equal_2();
  }

  Are_parallel_2
  are_parallel_2_object() const {
    return Are_parallel_2();
  }

  Oriented_side_of_bisector_2
  oriented_side_of_bisector_2_object() const {
    return Oriented_side_of_bisector_2();
  }

  Vertex_conflict_2
  vertex_conflict_2_object() const {
    return Vertex_conflict_2();
  }

  Finite_edge_interior_conflict_2
  finite_edge_interior_conflict_2_object() const {
    return Finite_edge_interior_conflict_2();
  }

  Infinite_edge_interior_conflict_2
  infinite_edge_interior_conflict_2_object() const {
    return Infinite_edge_interior_conflict_2();
  }

  Is_degenerate_edge_2
  is_degenerate_edge_2_object() const {
    return Is_degenerate_edge_2();
  }

  Arrangement_type_2
  arrangement_type_2_object() const {
    return Arrangement_type_2();
  }

  Oriented_side_2
  oriented_side_2_object() const {
    return Oriented_side_2();
  }

};

} //namespace CGAL

#endif // CGAL_SEGMENT_DELAUNAY_GRAPH_LINF_2_TRAITS_BASE_2_H
