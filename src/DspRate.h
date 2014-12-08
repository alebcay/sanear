#pragma once

#include "DspChunk.h"

#include <soxr.h>

namespace SaneAudioRenderer
{
    class DspRate final
    {
    public:

        DspRate() = default;
        DspRate(const DspRate&) = delete;
        DspRate& operator=(const DspRate&) = delete;
        ~DspRate();

        std::wstring Name() { return L"Rate"; }

        void Initialize(bool variable, uint32_t inputRate, uint32_t outputRate, uint32_t channels);
        bool Active();

        void Process(DspChunk& chunk);
        void Finish(DspChunk& chunk);

        void Adjust(REFERENCE_TIME delta);

    private:

        void DestroyBackend();

        soxr_t m_soxr = nullptr;
        bool m_variable = false;
        uint32_t m_inputRate;
        uint32_t m_outputRate;
        uint32_t m_channels;
        REFERENCE_TIME m_delta;

        const double m_maxVariableRateMultiplier = 2;
    };
}
