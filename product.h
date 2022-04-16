//22100661 정다훈
typedef struct{
    char name[30]; // 제품명
    char exp[200]; // 제품 설명
    char weight[50]; // 중량
    int price, type; // 가격, 배송방법(1:새벽배송 / 2:택배배송)
} Product;

int selectMenu();
int selectDataNo(Product *p, int count);
int loadData(Product *p); // 파일에 저장된 데이터를 불러오는 함수
int createProduct(Product *p); // 제품을 추가하는 함수
void readProduct(Product p); // 하나의 제품 출력 함수
void listProduct(Product *p, int count); // 전체 등록된 제품 리스트 출력
void searchProduct(Product *p, int count); // 제품이름 검색
int deleteProduct(Product *p); // 제품 정보 삭제
void saveProduct(Product *p, int count); // 제품 정보 저장
int updateProduct(Product *p); // 제품 정보 수정장
