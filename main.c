//22100661 정다훈
/* main.c */
#include <stdio.h>
#include <string.h>
#include "manager.h"

int main(){
    Product p[20];
    int idx = 0, count = 0, menu;

    count = loadData(p);
    idx = count;

    while(1){
   	menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count > 0) listProduct(p, idx);
        }
        else if (menu == 2) count += createProduct(&p[idx++]);
        else if (menu == 3){
            int no = selectDataNo(p, idx);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(&p[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(p, idx);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int delok;
            printf("정말로 삭제하시겠습니까? (삭제 : 1)" );
            scanf("%d", &delok);
            if(delok == 1){
                if(deleteProduct(&p[no-1])) count--;
                printf("=> 삭제됨!\n");
            }
        }
        else if(menu == 5) saveProduct(p, idx);
        else if(menu == 6) searchProduct(p, idx);
        else if(menu == 7) searchWeight(p, idx);
        else if(menu == 8) searchType(p, idx);
    }
    printf("종료됨!\n");
    return 0;
}
