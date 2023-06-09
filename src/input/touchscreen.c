#include <input_manager.h>
#include <stdio.h>
#include <tslib.h>

struct tsdev* g_ts;

static int TouchScreenGetInputEvent(PInputEvent ptInputEvent)
{
	struct ts_sample samp;
	int ret;
	
	ret = ts_read(g_ts, &samp, 1);
	if(ret != 1) return -1;

	// 将samp里面的值逐个赋给ptInputEvent，作转换
	ptInputEvent->iType = INPUT_TYPE_TOUCH;
	ptInputEvent->iX = samp.x;
	ptInputEvent->iY = samp.y;
	ptInputEvent->iPressure = samp.pressure;
	ptInputEvent->tTime = samp.tv;

	return 0;
}
static int TouchScreenDeviceInit(void)
{
	g_ts = ts_setup(NULL, 0);
	if (!g_ts)
	{
		printf("ts_setup err\n");
		return -1;
	}
	return 0;
}
static int TouchScreenDeviceExit(void)
{
	ts_close(g_ts);
	return 0;
}

static InputDevice g_tTouchScreenDev = 
{
	.name = "touchscreen",
	.GetInputEvent = TouchScreenGetInputEvent,
	.DeviceInit = TouchScreenDeviceInit,
	.DeviceExit = TouchScreenDeviceExit
};

void TouchScreenDeviceRegister(void)
{
	RegisterInputDevice(&g_tTouchScreenDev);	
}

/*单元测试代码*/
#if 0
int main(int argc, char * * argv)
{
	InputEvent event;
	int ret;

	g_tTouchScreenDev.DeviceInit();
	while(1)
	{
		ret = g_tTouchScreenDev.GetInputEvent(&event);
		if(ret)
		{
			printf("GetInputEvent Err!\n");
			return -1;
		}
		else
		{
			printf("Type       : %d\n", event.iType);
			printf("iX         : %d\n", event.iX);
			printf("iY         : %d\n", event.iY);
			printf("iPressure  : %d\n", event.iPressure);
		}
	}
	
	return 0;
}
#endif