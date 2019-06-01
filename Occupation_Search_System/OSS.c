#include "json.h"

void printCompanies(Company *companies, int count) {
    char *sizeToStr;
    printf("\n*********************** Companies *************************\n");
    for (int i = 0; i < count; i++) {
        if (companies[i].size == 1)
            sizeToStr = "Large";
        else if (companies[i].size == 2)
            sizeToStr = "Medium";
        else if (companies[i].size == 3)
            sizeToStr = "Small";
        else if (companies[i].size == 4)
            sizeToStr = "Startup";

        printf("\r\n[%d] %s \r\n", i + 1, companies[i].name);
        printf("Size : %s \r\n", sizeToStr);
        printf("Recruiting # : %d \r\n", companies[i].recruitNum);
        printf("Coding Test : %s \r\n", companies[i].coding);
        printf("Salary : %d \r\n", companies[i].salary);
        printf("Location : %s \r\n", companies[i].location);
        printf("City : %s \r\n", companies[i].city);
        printf("Available Positions : \r\n");

        for(int j = 0; j < companies[i].positionCount; j++){
            printf(" %d. %s \r\n", j + 1, companies[i].positions[j]);
        }
    }
    printf("************************************************************\n\n");
}

void printschools(School *schools, int count) {
    char *sizeToStr;
    printf("\n*********************** Graduate Schools List *************************\n");
    for (int i = 0; i < count; i++) {
        printf("\r\n[%d] %s \r\n", i + 1, schools[i].name);
        printf("Location : %s \r\n", schools[i].location);
        printf("Type : \r\n");

        for(int j = 0; j < schools[i].typeCount; j++){
            printf(" %d. %s \r\n", j + 1, schools[i].type[j]);
        }
    }
    printf("*************************************************************************\n\n");
}


void chooseGraduateSchool(School *schools, int count){
    char name[20];
    char *sizeToStr;
    int num=0;
    
    printf("Enter a graduate school name: ");
    scanf("%s", name);
    printf("\n************************************************************************");
    printf("\nResults:");
    for (int i = 0; i < count; i++) {
        // printf("%s",companies[i].name);

        if(!(strcmp(name, schools[i].name))){
            printf("\r\n[%d] %s \r\n", i + 1, schools[i].name);
            printf("Available Types : \r\n");
            for(int j=0; j<schools[i].typeCount; j++){
                printf(" %d. %s \r\n", j+1,schools[i].type[j]);
            }
        }
    }
    printf("\n************************************************************************\n");
 
    printf("Where do you wnat to apply? Choose the number.\n");
    if(!strcmp("HANDONG", name)){
    while(num != 4){
        scanf("%d", &num);

        switch (num)
        {
        case 1: case 2: case 3:
            printf("I recommad you to apply Lee Won Hyung professor's lab");
            printf(" Choose again\n");
            break;
        case 4:
            printf("Apply now \nemail: whlee@handong.edu");
            break;      
        default:
            break;
        }
    }
    }

    else if(!strcmp("UNIST", name)){
        scanf("%d", &num);  
        printf("%d. %s \r\n", num,schools[1].type[num-1]);
        printf("I recommend the lab of Professor Lee Won-hyung of Handong University.\n");

    } else if(!strcmp("Kyungpook National University", name)){
        scanf("%d", &num);  
        printf("%d. %s \r\n", num,schools[2].type[num-1]);
        printf("I recommend the lab of Professor Lee Won-hyung of Handong University.\n");

    } else if(!strcmp("Hanyang University", name)){
        scanf("%d", &num);  
        printf("%d. %s \r\n", num,schools[3].type[num-1]);
        printf("I recommend the lab of Professor Lee Won-hyung of Handong University.\n");
    }



}


void searchByName(Company *companies, int count){
    char name[20];
    char *sizeToStr;
    int noExistCount = 0;
    
    printf("Enter a company name: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if(toLower(strlen(companies[i].name), name, companies[i].name)) {
            if (companies[i].size == 1){
                sizeToStr = "Large";
            }
            else if (companies[i].size == 2){
                sizeToStr = "Medium";
            }
            else if (companies[i].size == 3){
                sizeToStr = "Small";
            }
            else{
                sizeToStr = "Startup";
            }

            printf("\r\n[%d] %s \r\n", i + 1, companies[i].name);
            printf("Recruiting # : %d \r\n", companies[i].recruitNum);
            printf("Coding Test : %s \r\n", companies[i].coding);
            printf("Salary : %d \r\n", companies[i].salary);
            printf("Available Positions : \r\n");
            for(int j=0; j<companies[i].positionCount; j++){
                printf(" %d. %s \r\n", j+1,companies[i].positions[j]);
            }
        } else {
            noExistCount++;
        }
    }
    if(noExistCount == count) {
        noExist();
    }
    printf("\n");
}

void searchBySize(Company *companies, int count){
    char size[10];
    char *sizeToStr;
    int selectedComapny;
    bool companyInput = true;
    int noExistCount = 0;


    do {
        printf("Enter size of company (ex. large, medium, small, startup): ");
        scanf("%s", size);

        if(toLower(5, "Small", size) || toLower(5, "Large", size)
        || toLower(6, "Medium", size) || toLower(7, "Startup", size)) {
            companyInput = false;
        } else {
            printf("kind of company size Large or medium or small or startup.\n");
        }
    } while(companyInput);

    for (int i = 0; i < count; i++) {
        //convert size number to string equivalent
        if (companies[i].size == 1){
            sizeToStr = "Large";
        }
        else if (companies[i].size == 2){
            sizeToStr = "Medium";
        }
        else if (companies[i].size == 3){
            sizeToStr = "Small";
        }
        else{
            sizeToStr = "Startup";
        }
        if(toLower(strlen(sizeToStr), sizeToStr, size)){ //if user input and company size are equal
            printf("\r\n[%d] %s \r\n", i + 1, companies[i].name);
            printf("Size : %s \r\n", sizeToStr);
        } else {
            noExistCount++;
        }
    }

    if(noExistCount == count) {
        noExist();
    } else {
        printf("Enter number of company for more information: ");
        scanf("%d", &selectedComapny);
        printf("\r\n%s \r\n", companies[selectedComapny-1].name);
        printf("\r\nRecruiting # : %d \r\n", companies[selectedComapny-1].recruitNum);
        printf("Coding Test : %s \r\n", companies[selectedComapny-1].coding);
        printf("Salary : %d \r\n", companies[selectedComapny-1].salary);
        printf("Available Positions : \r\n");
        for(int j=0; j<companies[selectedComapny-1].positionCount; j++){
            printf(" %d. %s \r\n", j+1,companies[selectedComapny-1].positions[j]);
        }
    }
    printf("\n");
}


void searchBySalary(Company *companies, int count){
    int minSalary;
    char *sizeToStr;
    int selectedComapny;
    int noExistCount = 0;
    
    printf("Enter desired minimum salary : ");
    scanf("%d", &minSalary);

    for (int i = 0; i < count; i++) {
        if(companies[i].salary > minSalary){ //if user input and company size are equal

            printf("\r\n[%d] %s \r\n", i + 1, companies[i].name);
            printf("Salary : %d \r\n", companies[i].salary);
        } else {
            noExistCount++;
        }
    }

    if(noExistCount == count) {
        noExist();
    } else {
        printf("Enter number of company for more information: ");
        scanf("%d", &selectedComapny);
        //convert size number to string equivalent
        if (companies[selectedComapny-1].size == 1){
            sizeToStr = "Large";
        } else if (companies[selectedComapny-1].size == 2){
            sizeToStr = "Medium";
        } else if (companies[selectedComapny-1].size == 3){
            sizeToStr = "Small";
        } else{
            sizeToStr = "Startup";
        }
        printf("Size : %s \r\n", sizeToStr);
        printf("\r\n%s \r\n", companies[selectedComapny-1].name);
        printf("\r\nRecruiting # : %d \r\n", companies[selectedComapny-1].recruitNum);
        printf("Coding Test : %s \r\n", companies[selectedComapny-1].coding);
        printf("Salary : %d \r\n", companies[selectedComapny-1].salary);
        printf("Available Positions : \r\n");
        for(int j=0; j<companies[selectedComapny-1].positionCount; j++){
            printf(" %d. %s \r\n", j+1,companies[selectedComapny-1].positions[j]);
        }
    }
    printf("\n");
}


void searchByJob(Company *companies, int companyCount, char jobs[][40], int jobCount){
    int jobSelection;
    char *sizeToStr;
    int selectedComapny;
    char jobToSearch[40];
    for (int c = 0; c < jobCount; c++) {
            printf("[%d] %s \r\n", c + 1, jobs[c]);
    }

    printf("Enter your choice from position list : ");
    scanf("%d", &jobSelection);

    strcpy(jobToSearch,jobs[jobSelection-1]);
    printf("Selected job is : %s \r\n", jobToSearch);

    for (int i = 0; i < companyCount; i++) {
    // printf("%s",companies[i].name);
        for(int j =0; j < companies[i].positionCount; j++){
            if(!strcmp(companies[i].positions[j], jobToSearch)){ //if job is found
                    //print company info
                    if (companies[i].size == 1){
                        sizeToStr = "Large";
                    }
                    else if (companies[i].size == 2){
                        sizeToStr = "Medium";
                    }
                    else if (companies[i].size == 3){
                        sizeToStr = "Small";
                    }
                    else{
                        sizeToStr = "Startup";
                    }

                    printf("\r\n[%d] %s \r\n", i + 1, companies[i].name);
                    printf("Position: \r\n");
                    printf(" %s \r\n", companies[i].positions[j]);
                    
            }
        }
    }
    printf("Enter number of company for more information: ");
    scanf("%d", &selectedComapny);
    //convert size number to string equivalent
    if (companies[selectedComapny-1].size == 1){
        sizeToStr = "Large";
    } else if (companies[selectedComapny-1].size == 2){
        sizeToStr = "Medium";
    } else if (companies[selectedComapny-1].size == 3){
        sizeToStr = "Small";
    } else{
        sizeToStr = "Startup";
    }
    printf("Size : %s \r\n", sizeToStr);
    printf("\r\n%s \r\n", companies[selectedComapny-1].name);
    printf("\r\nRecruiting # : %d \r\n", companies[selectedComapny-1].recruitNum);
    printf("Coding Test : %s \r\n", companies[selectedComapny-1].coding);
    printf("Salary : %d \r\n", companies[selectedComapny-1].salary);
    printf("Available Positions : \r\n");
    for(int j=0; j<companies[selectedComapny-1].positionCount; j++){
        printf(" %d. %s \r\n", j+1,companies[selectedComapny-1].positions[j]);
    }
    printf("\n");
}

void enterInfo(User* ourUser,Company *companies, int companyCount){
    char answer[5];
    char salary[10];
    int selected[companyCount];
    int qnum = 0;
    char *sizeToStr;
    int selectedComapny = 0;
    printf(">> What is your name? : ");
    scanf("%s", ourUser[0].name);
    printf("Hi %s, Welcome!", ourUser[0].name);
  
    printf("\r\n\n>>Where do you live or want to work? : ");
    scanf("%s", ourUser[0].city);
    printf("So you want to work at %s.\r\n", ourUser[0].city);
    qnum++;


    printf("\n>>How about working abroad? Yes/No: ");
    scanf("%s", answer);
    if(!strcmp(answer, "Yes")){
        ourUser[0].workAbroad=1;
    }else{
        ourUser[0].workAbroad=0;
    }
    if(ourUser[0].workAbroad){
        printf("So you don't mind working overseas!\r\n");
    }else{
        printf("Okay we understand. You like staying closer to home.\r\n");
    }
    

    printf("\n>>How much salary would be okay for you? : ");
    scanf("%s", salary);
    ourUser[0].salary = atoi(salary);
    if( ourUser[0].salary>=7000){
        printf("%d is quite a bit of money!\r\n", ourUser[0].salary);
    }else{
        printf("%d sounds like a good amount.\r\n", ourUser[0].salary);
    }
    qnum++;

    printf("\n>>Now we will run our algorithm....\r\n");
    Sleep(1800);
//     sleep(1.8);
    printf("Making calculations...\r\n");
    Sleep(1800);
//     sleep(1.8);
    printf("Making a cup of coffee...\r\n");
    Sleep(1800);
//     sleep(1.8);
    printf("Finalyzing..");
    for (int g = 0; g < 6; g++)
    {
        Sleep(600);
//         sleep(0.6);

        printf("...");
    }
    printf("\r\n\n>>Here are the results!\r\n");
    Sleep(1500);
//     sleep(1.5);

    //recommend

    for (int i = 0; i < companyCount; i++){
        selected[i] = 0;
    }

    for (int i = 0; i < companyCount; i++)
    {
        if (companies[i].salary >= ourUser[0].salary)
        {
            selected[i]++;
        }

        if (strstr(ourUser[0].city, companies[i].city) != NULL)
        {   
            selected[i]++;
        }
        if (ourUser[0].workAbroad==1){
            if (strstr(companies[i].city, "Seoul")==NULL){
                selected[i]++;
            }
        }
    }

    for (int selectedComapny = 0; selectedComapny < companyCount; selectedComapny++)
    {
        if (selected[selectedComapny] == qnum)
        {

            if (companies[selectedComapny].size == 1)
            {
                sizeToStr = "Large";
            }
            else if (companies[selectedComapny].size == 2)
            {
                sizeToStr = "Medium";
            }
            else if (companies[selectedComapny].size == 3)
            {
                sizeToStr = "Small";
            }
            else
            {
                sizeToStr = "Startup";
            }
            printf("\r\n[%d] %s \r\n", selectedComapny,companies[selectedComapny].name);
            printf("Size : %s", sizeToStr);
            printf("\r\nRecruiting # : %d \r\n", companies[selectedComapny].recruitNum);
            printf("Coding Test : %s \r\n", companies[selectedComapny].coding);
            printf("Salary : %d \r\n", companies[selectedComapny].salary);
            printf("Location : %s \r\n", companies[selectedComapny].city);

            printf("Available Positions : \r\n");
            for (int j = 0; j < companies[selectedComapny].positionCount; j++)
            {
                printf(" %d. %s \r\n", j + 1, companies[selectedComapny].positions[j]);
            }
        }
    }

    if(selectedComapny == 0){
        printf("\nOops... seems like there is no company for you. Sorry :( \n");
    }
}

bool toLower(int strLen, char* voca, char* comvoca) {
    int totalLen = 0;
    for(int i = 0; i < strLen; i++) {
        if(tolower(voca[i]) == tolower(comvoca[i])) {
            totalLen++;
        }
    }
    if(totalLen == strLen) {
        return true;
    }
    return false;
}

void noExist() {
    printf("There is no company that meets the conditions.\n\n");
}
