#pragma once
#include "Sound.h"
class DynamicSound :
    public Sound
{
public:
    DynamicSound(std::function<void(int16_t*, int, int)> generateFunction, double length);
    ~DynamicSound();

    virtual void Play(bool loop = false) override;

    virtual void SetVolume(float volume) override;
    virtual void SetPitch(float pitch) override;
    virtual void SetPan(float pan) override;

    size_t GetSampleCount();
private:
    std::unique_ptr<DirectX::DynamicSoundEffectInstance> m_dynamicSoundEffectInstance;
    std::function<void(int16_t*, int, int)> m_generateFunction;

    size_t m_sampleCount;
    std::vector<uint8_t> m_audioBytes;
};