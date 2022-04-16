#include <stdio.h>
#include <string.h>
#include "product.h"

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
    }
    printf("종료됨!\n");
    return 0;
}

int selectMenu(){
    int menu;
    printf("\n*** Product ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("5. 파일저장\n");
    printf("6. 메뉴이름검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int selectDataNo(Product *p, int count){
    int no;
    listProduct(p, count);
    printf("\n번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}

int loadData(Product *p){  // 파일에 저장된 데이터를 불러오는 함수
    int count;
    FILE* file = fopen("product.txt", "rt");
    if(file == NULL){
        puts("=> 파일 없음\n");
        return 0;
    }
    for(int i=0; i<100; i++){
        fscanf(file, "%s", p[i].name);
        if(feof(file)) break;
        fscanf(file, "%d", &p[i].price);
        fscanf(file, "%s", p[i].weight);
        fscanf(file, "%d", &p[i].type);
        fscanf(file, "%s", p[i].exp);
        count++;
    }
    fclose(file);
    printf("=> 로딩성공!\n");
    return count;
} 

int createProduct(Product *p){  // 제품을 추가하는 함수
    printf("제품명 : ");
    scanf("%s", p->name);
    printf("제품 설명 : ");
    scanf("%s", p->exp);
    printf("중량 : ");
    scanf("%s", p->weight);
    printf("가격 : ");
    scanf("%d", &p->price);
    printf("배송방법(1:새벽배송 / 2:택배배송) : ");
    scanf("%d", &p->type);
    return 1;
} 

void readProduct(Product p){    // 하나의 제품 출력 함수
    printf("%s  %d   %s      %d   %s\n", p.name, p.price, p.weight, p.type, p.exp);
} 

void listProduct(Product *p, int count){   // 전체 등록된 제품 리스트 출력
    printf("No  Name  price  weight   type  explain\n");
    printf("============================================\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        printf("%2d", i+1);
        readProduct(p[i]);
    }
}

void searchProduct(Product *p, int count){    // 제품이름 검색
    int scnt = 0;
    char search[20];

    printf("검색할 이름? ");
    scanf("%s", search);
    
    printf("No  Name  price  weight   type  explain\n");
    printf("============================================\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        if(strstr(p[i].name, search)){
            printf("%2d", i+1);
            readProduct(p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!\n");
}

int updateProduct(Product *p){
    printf("제품명 : ");
    scanf("%s", p->name);
    printf("제품 설명 : ");
    scanf("%s", p->exp);
    printf("중량 : ");
    scanf("%s", p->weight);
    printf("가격 : ");
    scanf("%d", &p->price);
    printf("배송방법(1:새벽배송 / 2:택배배송) : ");
    scanf("%d", &p->type);
    return 1;
}

int deleteProduct(Product *p){  // 제품 정보 삭제
    p->price = -1;
    return 1;
} 

void saveProduct(Product *p, int count){    // 제품 정보 저장
    FILE* file = fopen("product.txt", "wt");
    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        fprintf(file, "%s %d %s %d %s\n", p[i].name, p[i].price, p[i].weight, p[i].type, p[i].exp);
    }
    fclose(file);
    printf("=> 저장됨!\n");
}
