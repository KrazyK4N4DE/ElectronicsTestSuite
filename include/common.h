#ifndef __COMMON_H__
#define __COMMON_H__

#ifndef NULL
#define NULL (void* )0
#endif

/*LCD坐标系块区域大小分辨率*/
typedef struct Region
{
    int leftUpX, leftUpY;  // 描述位置的左上角X、Y坐标
    int width, height;  // 有多宽、有多高
}Region, * PRegion;

/*笛卡尔坐标系块区域大小分辨率*/
typedef struct RegionCartesian
{
    int leftUpX, leftUpY;  // 描述位置的左上角X、Y坐标
    int width, height;  // 有多宽、有多高
}RegionCartesian, * PRegionCartesian;

#endif