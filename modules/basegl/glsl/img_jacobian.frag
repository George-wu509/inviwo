/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2016-2017 Inviwo Foundation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 *********************************************************************************/

#include "utils/structs.glsl"

uniform ImageParameters outportParameters_;

uniform sampler2D inport_;

uniform int renormalization_ = 1;

void main() {
    vec2 dx = vec2(outportParameters_.reciprocalDimensions.x, 0);
    vec2 dy = vec2(0, outportParameters_.reciprocalDimensions.y);

    vec2 texCoords = gl_FragCoord.xy * outportParameters_.reciprocalDimensions;
    // compute Jacobian using central differences
    vec2 du = (texture(inport_,texCoords + dx ).xy - texture(inport_,texCoords - dx ).xy) * 0.5;
    vec2 dv = (texture(inport_,texCoords + dy ).xy - texture(inport_,texCoords - dy ).xy) * 0.5;

    if (renormalization_  > 0) {
        du /= outportParameters_.reciprocalDimensions.xy;
        dv /= outportParameters_.reciprocalDimensions.xy;
    }

    mat2 m = mat2(du, dv);
#if defined(INVERT_JACOBIAN)
    m = inverse(m);
#endif

    FragData0 = vec4(m[0], m[1]);
}