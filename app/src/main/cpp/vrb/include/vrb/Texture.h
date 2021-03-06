/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VRB_TEXTURE_DOT_H
#define VRB_TEXTURE_DOT_H

#include "vrb/Forward.h"
#include "vrb/MacroUtils.h"

#include "vrb/gl.h"
#include <string>

namespace vrb {

class Texture {
public:
  void Bind();
  void Unbind();
  std::string GetName() const;
  GLenum GetTarget() const;
  void SetName(const std::string& aName);
  void SetTextureParameter(GLenum aName, GLint aParam);
  GLuint GetHandle() const;
protected:
  struct State;
  Texture(State& aState, CreationContextPtr& aContext);
  virtual ~Texture();

  virtual void AboutToBind() {}

private:
  State& m;
  Texture() = delete;
  VRB_NO_DEFAULTS(Texture)
};

} // namespace vrb

#endif // VRB_TEXTURE_DOT_H
