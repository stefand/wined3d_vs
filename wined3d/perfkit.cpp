#define NVPM_INITGUID
#include "NvPmApi.Manager.h"

#define INSTRUMENTATION_ENABLED

static NvPmApiManager S_NVPMManager;
extern NvPmApiManager *GetNvPmApiManager() {return &S_NVPMManager;}
const NvPmApi *GetNvPmApi() {return S_NVPMManager.Api();}

int MyEnumFunc(NVPMCounterID unCounterIndex, const char *pcCounterName);

extern "C"
{
	NVPMContext hNVPMContext(0);
	NVPMCounterID rop, shd, busy, texture;

	void perfkit_init(HGLRC ctx)
	{
		return;
		if(GetNvPmApiManager()->Construct(L"C:\\users\\stefan\\desktop\\perfkit_3.0.1.13135\\bin\\win7_x86\\NvPmApi.Core.dll") != S_OK)
		{
			MessageBoxA(NULL, "Nvperfkit error 1", "0", MB_OK);
			return;
		}
		NVPMRESULT nvResult;
		if((nvResult = GetNvPmApi()->Init()) != NVPM_OK)
		{
			MessageBoxA(NULL, "Nvperfkit error 2", "0", MB_OK);
			return;
		}

		if(GetNvPmApi()->CreateContextFromOGLContext((APIContextHandle) ctx, &hNVPMContext) != NVPM_OK)
		{
			MessageBoxA(NULL, "Nvperfkit error 3", "0", MB_OK);
			return;
		}

		GetNvPmApi()->GetCounterIDByContext(hNVPMContext, "gpu_busy", &busy);
		GetNvPmApi()->GetCounterIDByContext(hNVPMContext, "rop_busy", &rop);
		GetNvPmApi()->GetCounterIDByContext(hNVPMContext, "shader_busy", &shd);
		GetNvPmApi()->GetCounterIDByContext(hNVPMContext, "texture_busy", &texture);

		if (GetNvPmApi()->AddCounter(hNVPMContext, rop) != NVPM_OK)
		{
			MessageBoxA(NULL, "Nvperfkit error 5", "0", MB_OK);
			return;
		}
		if (GetNvPmApi()->AddCounter(hNVPMContext, shd) != NVPM_OK)
		{
			MessageBoxA(NULL, "Nvperfkit error 6", "0", MB_OK);
			return;
		}
		if (GetNvPmApi()->AddCounter(hNVPMContext, busy) != NVPM_OK)
		{
			MessageBoxA(NULL, "Nvperfkit error 7", "0", MB_OK);
			return;
		}
		if (GetNvPmApi()->AddCounter(hNVPMContext, texture) != NVPM_OK)
		{
			MessageBoxA(NULL, "Nvperfkit error 8", "0", MB_OK);
			return;
		}
	}

#include "wine/debug.h"
	WINE_DEFAULT_DEBUG_CHANNEL(d3d);

	static float get_counter(NVPMCounterID counter)
	{
		float ret;
		UINT64 events, cycles = 0;
		GetNvPmApi()->GetCounterValue(hNVPMContext, counter, 0, &events, &cycles);
		ret = (float) events / (float) cycles;
		return ret * 100.0f;
	}

	void perfkit_frame()
	{
		UINT nCount;
		float gpu_busy, rop_busy, shd_busy, texture_busy;
		return;
		GetNvPmApi()->Sample(hNVPMContext, NULL, &nCount);
#if 0
		GetNvPmApi()->GetCounterValue(hNVPMContext, idle, 0, &events, &cycles);
		idle_val = (float) events / (float) cycles;
		ERR("gpu_idle: %f\n", idle_val);
#endif
		gpu_busy = get_counter(busy);
		rop_busy = get_counter(rop);
		shd_busy = get_counter(shd);
		texture_busy = get_counter(texture);
		ERR("gpu_busy: %2f, rop_busy: %2f, shd_busy: %2f, texture_busy: %2f\n", gpu_busy, rop_busy, shd_busy, texture_busy);
	}
}

int MyEnumFunc(NVPMCounterID unCounterIndex, const char *pcCounterName)
{
    char zString[200], zLine[400];
    NVPMUINT unLen;

    unLen = 200;
    if(GetNvPmApi()->GetCounterDescription(unCounterIndex, zString, &unLen) == NVPM_OK) 
    {
		if(GetNvPmApi()->GetCounterName(unCounterIndex, zLine, &unLen) == NVPM_OK)

		ERR("Counter %d [%s] : %s\n", unCounterIndex, zString, zLine);
    }

    return(NVPM_OK);
}
