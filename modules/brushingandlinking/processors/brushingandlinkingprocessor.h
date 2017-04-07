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

#ifndef IVW_BRUSHINGANDLINKINGPROCESSOR_H
#define IVW_BRUSHINGANDLINKINGPROCESSOR_H

#include <inviwo/core/common/inviwo.h>
#include <inviwo/core/ports/imageport.h>
#include <inviwo/core/processors/processor.h>
#include <inviwo/core/properties/ordinalproperty.h>
#include <modules/brushingandlinking/brushingandlinkingmanager.h>
#include <modules/brushingandlinking/brushingandlinkingmoduledefine.h>
#include <modules/brushingandlinking/ports/brushingandlinkingports.h>

namespace inviwo {

/** \docpage{org.inviwo.BrushingAndLinkingProcessor, Brushing And Linking Processor}
 * ![](org.inviwo.BrushingAndLinkingProcessor.png?classIdentifier=org.inviwo.BrushingAndLinkingProcessor)
 * Explanation of how to use the processor.
 *
 * ### Inports
 *   * __<Inport1>__ <description>.
 *
 * ### Outports
 *   * __<Outport1>__ <description>.
 *
 * ### Properties
 *   * __<Prop1>__ <description>.
 *   * __<Prop2>__ <description>
 */
class IVW_MODULE_BRUSHINGANDLINKING_API BrushingAndLinkingProcessor : public Processor {
public:
    BrushingAndLinkingProcessor();
    virtual ~BrushingAndLinkingProcessor() = default;

    virtual void process() override;

    virtual const ProcessorInfo getProcessorInfo() const override;

    virtual void invokeEvent(Event* event) override;

    static const ProcessorInfo processorInfo_;

    BrushingAndLinkingOutport& getOutport() { return outport_; }

private:
    BrushingAndLinkingOutport outport_;
    std::shared_ptr<BrushingAndLinkingManager> manager_;
};

}  // namespace

#endif  // IVW_BRUSHINGANDLINKINGPROCESSOR_H