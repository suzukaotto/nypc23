#include <stdio.h>

int main(void) {
    int map_size, y, x;
    int atk_size, atk_range;
    int mogi_catch, mogi_max=0;
    
    scanf("%d", &map_size);
    int map[map_size][map_size];
    
    scanf("%d", &atk_size);
    
    for(y=0; y<map_size; y++)
        for(x=0; x<map_size; x++)
            scanf("%d", &map[y][x]);
	
    // 십자가 검토 
	for(y=0; y<map_size; y++){
		for(x=0; x<map_size; x++){
			mogi_catch=0;
			mogi_catch+=map[y][x];
        	for(atk_range=1; atk_range<=atk_size; atk_range++){
        		if(y+atk_range < map_size)
        			mogi_catch+=map[y+atk_range][x];
        		if(y-atk_range >= 0)
					mogi_catch+=map[y-atk_range][x];
        		if(x+atk_range < map_size)
        			mogi_catch+=map[y][x+atk_range];
        		if(x-atk_range >= 0)
					mogi_catch+=map[y][x-atk_range];
			}
			mogi_max=(mogi_catch>mogi_max) ? mogi_catch : mogi_max;
		}
	}
	
	// 엑스 검토 
	for(y=0; y<map_size; y++){
		for(x=0; x<map_size; x++){
			mogi_catch=0;
			mogi_catch+=map[y][x];
        	for(atk_range=1; atk_range<=atk_size; atk_range++){
        		//좌상 y- x- 
        		if(y-atk_range >= 0 && x-atk_range >= 0)
        			mogi_catch+=map[y-atk_range][x-atk_range];
        		//우상 y- x+
        		if(y-atk_range >= 0 && x+atk_range < map_size)
        			mogi_catch+=map[y-atk_range][x+atk_range];
				//좌하 y+ x-
        		if(y+atk_range < map_size && x-atk_range >= 0)
        			mogi_catch+=map[y+atk_range][x-atk_range];
        		//우하 y+ x+
        		if(y+atk_range < map_size && x+atk_range < map_size)
        			mogi_catch+=map[y+atk_range][x+atk_range];
			}
			mogi_max=(mogi_catch>mogi_max) ? mogi_catch : mogi_max;
		}
	}
	
	printf("%d", mogi_max);
	
	return 0;
}
