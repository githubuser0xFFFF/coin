/**************************************************************************\
 *
 *  Copyright (C) 1998-2000 by Systems in Motion.  All rights reserved.
 *
 *  This file is part of the Coin library.
 *
 *  This file may be distributed under the terms of the Q Public License
 *  as defined by Troll Tech AS of Norway and appearing in the file
 *  LICENSE.QPL included in the packaging of this file.
 *
 *  If you want to use Coin in applications not covered by licenses
 *  compatible with the QPL, you can contact SIM to aquire a
 *  Professional Edition license for Coin.
 *
 *  Systems in Motion AS, Prof. Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ sales@sim.no Voice: +47 22114160 Fax: +47 67172912
 *
\**************************************************************************/

/*!
  \class SoCoordinate4 SoCoordinate4.h Inventor/nodes/SoCoordinate4.h
  \brief The SoCoordinate4 class is a node for providing coordinates to shape nodes.
  \ingroup nodes

  When encountering nodes of this type during traversal, the
  coordinates it contains will be put on the statestack for later use
  by shape nodes of types which needs coordinate sets (like SoFaceSet
  nodes or SoPointSet nodes).

  The fourth element of the coordinate vectors is used for
  normalization. A node of this type where all the normalization
  values are equal to 1.0 is the equivalent of setting up an
  SoCoordinate3 node.

  Note that an SoCoordinate4 node will \e replace the coordinates
  already present in the state (if any).

  \sa SoCoordinate3
*/

#include <Inventor/nodes/SoCoordinate4.h>

#include <Inventor/actions/SoCallbackAction.h>
#include <Inventor/actions/SoGLRenderAction.h>
#include <Inventor/actions/SoGetBoundingBoxAction.h>
#include <Inventor/actions/SoGetPrimitiveCountAction.h>
#include <Inventor/actions/SoPickAction.h>
#include <Inventor/elements/SoGLCoordinateElement.h>

/*!
  \var SoMFVec4f SoCoordinate4::point

  Coordinate set of 3D points as 4D vectors (each vector contains a 3D
  coordinate plus normalization value).
*/


// *************************************************************************

SO_NODE_SOURCE(SoCoordinate4);

/*!
  Constructor.
*/
SoCoordinate4::SoCoordinate4(void)
{
  SO_NODE_INTERNAL_CONSTRUCTOR(SoCoordinate4);

  SO_NODE_ADD_FIELD(point, (SbVec4f(0.0f, 0.0f, 0.0f, 1.0f)));
}

/*!
  Destructor.
*/
SoCoordinate4::~SoCoordinate4()
{
}

// Doc from superclass.
void
SoCoordinate4::initClass(void)
{
  SO_NODE_INTERNAL_INIT_CLASS(SoCoordinate4);

  SO_ENABLE(SoGetBoundingBoxAction, SoCoordinateElement);
  SO_ENABLE(SoGLRenderAction, SoGLCoordinateElement);
  SO_ENABLE(SoPickAction, SoCoordinateElement);
  SO_ENABLE(SoCallbackAction, SoCoordinateElement);
  SO_ENABLE(SoGetPrimitiveCountAction, SoCoordinateElement);
}

// Doc from superclass.
void
SoCoordinate4::getBoundingBox(SoGetBoundingBoxAction * action)
{
  SoCoordinate4::doAction(action);
}

// Doc from superclass.
void
SoCoordinate4::doAction(SoAction * action)
{
  SoCoordinateElement::set4(action->getState(), this,
                            point.getNum(), point.getValues(0));
}

// Doc from superclass.
void
SoCoordinate4::GLRender(SoGLRenderAction * action)
{
  SoCoordinate4::doAction(action);
}

// Doc from superclass.
void
SoCoordinate4::callback(SoCallbackAction * action)
{
  SoCoordinate4::doAction(action);
}

// Doc from superclass.
void
SoCoordinate4::pick(SoPickAction * action)
{
  SoCoordinate4::doAction(action);
}

// Doc from superclass.
void
SoCoordinate4::getPrimitiveCount(SoGetPrimitiveCountAction * action)
{
  SoCoordinate4::doAction(action);
}
