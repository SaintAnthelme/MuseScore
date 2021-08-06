#ifndef MU_VST_VSTFXPROCESSOR_H
#define MU_VST_VSTFXPROCESSOR_H

#include <memory>

#include "audio/ifxprocessor.h"

#include "internal/vstaudioclient.h"
#include "internal/vstplugin.h"
#include "vsttypes.h"

namespace mu::vst {
class VstFxProcessor : public audio::IFxProcessor
{
public:
    explicit VstFxProcessor(VstPluginPtr&& pluginPtr);

    void init();

    audio::AudioFxType type() const override;
    void setSampleRate(unsigned int sampleRate) override;
    bool active() const override;
    void setActive(bool active) override;
    void process(float* buffer, unsigned int sampleCount) override;

private:
    VstPluginPtr m_pluginPtr = nullptr;
    std::unique_ptr<VstAudioClient> m_vstAudioClient = nullptr;

    bool m_isActive = false;
};

using VstFxPtr = std::shared_ptr<VstFxProcessor>;
}

#endif // MU_VST_VSTFXPROCESSOR_H
