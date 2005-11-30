/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2005 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org/> for more information.
 *
 *  Systems in Motion, Postboks 1283, Pirsenteret, 7462 Trondheim, NORWAY.
 *  <URL:http://www.sim.no/>.
 *
\**************************************************************************/

#include "SoGLCgShaderProgram.h"

#include <assert.h>
#include <stdlib.h>

#include "SoGLCgShaderObject.h"

// *************************************************************************

SoGLCgShaderProgram::SoGLCgShaderProgram(void)
{
  this->fragmentShader = NULL;
  this->vertexShader = NULL;
}

SoGLCgShaderProgram::~SoGLCgShaderProgram()
{
}

void
SoGLCgShaderProgram::addShaderObject(SoGLCgShaderObject * shaderObject)
{
  if (shaderObject->isVertexShader()) {
    this->vertexShader = shaderObject;
  }
  else {
    this->fragmentShader = shaderObject;
  }
}

void
SoGLCgShaderProgram::removeShaderObjects(void)
{
  this->vertexShader = NULL;
  this->fragmentShader = NULL;
}

void
SoGLCgShaderProgram::enable(void)
{
  if (this->fragmentShader) this->fragmentShader->enable();
  if (this->vertexShader) this->vertexShader->enable();
}

void
SoGLCgShaderProgram::disable(void)
{
  if (this->fragmentShader) this->fragmentShader->disable();
  if (this->vertexShader) this->vertexShader->disable();
}

#if defined(SOURCE_HINT)
SbString
SoGLCgShaderProgram::getSourceHint(void) const
{
  SbString result;

  if (this->fragmentShader && this->fragmentShader->isActive()) {
    SbString str = this->fragmentShader->sourceHint;
    if (str.getLength() > 0) str += " ";
    result += str;
  }
  if (this->vertexShader && this->vertexShader->isActive()) {
    SbString str = this->vertexShader->sourceHint;
    if (str.getLength() > 0) str += " ";
    result += str;
  }
  return result;
}
#endif
