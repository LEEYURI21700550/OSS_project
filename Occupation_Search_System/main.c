#include "json.h"
//gcc -o OSS ./makelist.c ./OSS.c ./jsonparser.c ./main.c
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    int filesize = 0;
    char *fileName;
    char *doc;
    char trash;
    int bigcnt = 0; //total count including objects in value.
    int selectMenu = 0;
    int companyCount = 0;
    int schoolCount = 0;
    // Company *companies= malloc(sizeof(Company)*100);

    JSON json = {0};
    Company companies[20];
    School schools[20];
    User user[1];

    char jobs[][40] = { "Algorithm Developer", "Intern","App Developer", "Data Analyst", "Web Developer"
    , "DB Manager", "Project Manager", "ML Specialist", "Server Manager", "Big Data Specialist", "UX Specialist",
    "Web Secuity Specialist", "ADAS Developer", "ALGO Optimization Specialist"};
    int jobCount = 14;

    fileName = "OSS.json";
    doc = readfile(fileName, &filesize); // 파일 읽음
    fileCheck(fileName, doc); // 파일 내용 없으면 에러
    json_parse(doc, filesize, &json, &bigcnt); // 파서 시작
    printResult(&json, bigcnt); // 파서 출력
    makeCompanyTokens(&json, companies, bigcnt, &companyCount);// 파서결과를 Company Array에 저장
    makeGraduateSchoolToken(&json,schools, bigcnt, &schoolCount); //파서 결과를 School Array에 저장.
    freeJson(&json, bigcnt); // 토큰 free
    
    printf("\nHello!! Welcome to the world of Occupation Search System.\n");
    printf("Select one of the menus below :)\n");
    
    while(selectMenu < 9) {
        Sleep(2000);
        printf("************* Occupation Search System Application *************\n");
        printf("*                                                              *\n");
        printf("*    1.                 Show all company.                      *\n");
        printf("*    2.              Search by company name.                   *\n");
        printf("*    3.              Search by company size.                   *\n");
        printf("*    4.            Search by an annual income.                 *\n");
        printf("*    5.                Search by job type.                     *\n");
        printf("*    6.               Enter my Information.                    *\n");
        printf("*    7.                 I wont't get a job.                    *\n");
        printf("*    8.                   Quit Program                         *\n");
        printf("*                                                              *\n");
        printf("****************************************************************\n");
        printf("your select : ");
        scanf("%d", &selectMenu);
        scanf("%c", &trash);

        switch (selectMenu) {
        case 1:
            printCompanies(companies, companyCount);
            break;
        case 2:
            searchByName(companies, companyCount);
            break;
        case 3:
            searchBySize(companies, companyCount);
            break;
        case 4:
            searchBySalary(companies, companyCount);
            break;
        case 5:
            searchByJob(companies, companyCount, jobs, jobCount);
            break;
        case 6:
            enterInfo(user,companies, companyCount);
            break;
        case 7:
            printschools(schools, schoolCount);
            chooseGraduateSchool(schools, schoolCount);
            break;
        case 8:
            printf("OK. Bye! :)\n");
            return 0;
        default:
            break;
        }
    }

    return 0;
}
