#include "json.h"

int main(int argc, char **argv) {
    int filesize = 0;
    char *fileName;
    char *doc;
    int bigcnt = 0; //total count including objects in value.
    int selectMenu;
    int companyCount=0;
    // Company *companies= malloc(sizeof(Company)*100);

    JSON json = {0};
    Company companies[100];

            fileName = "OSS.json";
            doc = readfile(fileName, &filesize); // 파일 읽음
            fileCheck(fileName, doc); // 파일 내용 없으면 에러
            json_parse(doc, filesize, &json, &bigcnt); // 파서 시작
            printResult(&json, bigcnt); // 파서 출력
            makeCompanyTokens(&json, companies, bigcnt, &companyCount);// 파서결과를 Company Array에 저장
            printCompanies(companies, companyCount);
            freeJson(&json, bigcnt); // 토큰 free

    while(selectMenu < 8) {
        printf("\nHello!! Welcome to the world of Occupation Search System.\n");
        printf("Select one of the menus below :)\n");
        printf("************* Occupation Search System Application *************\n");
        printf("*                                                              *\n");
        printf("*    1.              Search by company name.                   *\n");
        printf("*    2.              Search by company size.                   *\n");
        printf("*    3.            Search by an annual income.                 *\n");
        printf("*    4.                Search by job type.                     *\n");
        printf("*    5.               Enter my Information.                    *\n");
        printf("*    6.               Recommended company.                     *\n");
        printf("*    7.                 I wont't get a job.                    *\n");
        printf("*    8.                   Quit Program                         *\n");
        printf("*                                                              *\n");
        printf("****************************************************************\n");
        printf("your select : ");
        scanf("%d", &selectMenu);

        switch (selectMenu) {
        case 1:
            
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
         printf("OK. Bye! :)\n");
            break;
        case 8:
            return 0;
        default:
            break;
        }
    }

    return 0;
}
