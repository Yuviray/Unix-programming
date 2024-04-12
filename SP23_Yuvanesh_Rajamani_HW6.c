//NAME: Yuvanesh Rajamani
//CS 4350-251-Unix Systems Programming
//Assignment Number: 6
//Due Date: 4/12/2023

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <netdb.h>

void createInputFile() {
    printf("1. INPUT-1-PA6.txt\n");
    system("touch INPUT-1-PA6.txt");
}

void filePermissionsBefore() {
    printf("2. File permission status is :\n");
    system("ls -l INPUT-1-PA6.txt");
}

void changeFileMode() {
    printf("3. File mode is changed\n");
    chmod("INPUT-1-PA6.txt", S_IRUSR | S_IWUSR | S_IXUSR);
}

void filePermissionsAfter() {
    printf("4. File permission status is :\n");
    system("ls -l INPUT-1-PA6.txt");
}

void appendText() {
    printf("5. Text is appended to the file.\n");
    FILE *inputFile = fopen("INPUT-1-PA6.txt", "a");
    fprintf(inputFile, "UNIX PROGRAMMING\nEXERCISE USING FILES\nBY HUSAIN GHOLOOM\n");
    fclose(inputFile);
    printf("6. File is closed.\n");
}

void outputContent() {
    printf("7. Content of the input file :\n");
    FILE *inputFile = fopen("INPUT-1-PA6.txt", "r");
    char c;
    while ((c = fgetc(inputFile)) != EOF) {
        printf("%c", c);
    }
    fclose(inputFile);
}

void outputCurrentDateTime() {
    printf("8. Current date and time is :\n");
    system("date");
}

void outputLastAccess() {
    printf("9. Time of last file access :\n");
    struct stat st;
    stat("INPUT-1-PA6.txt", &st);
    printf("Time of last access: %s", ctime(&st.st_atime));
}

void outputSystemName() {
    printf("10. System name :\n");
    system("uname -s");
}

void outputLocalHostName() {
    char hostname[256];
    gethostname(hostname, 256);
    printf("11. Local host name : %s\n", hostname);
}

void outputHostName() {
    char hostname[256];
    gethostname(hostname, 256);
    struct hostent *he = gethostbyname(hostname);
    printf("12. Host name : %s\n", he->h_name);
}

void outputProcessID() {
    printf("13. The process id : %d\n", getpid());
}

void outputParentProcessID() {
    printf("14. Parent process id : %d\n", getppid());
}

void outputProcessPriority() {
    printf("15. Priority level of the process : %ld\n", sysconf(_SC_NPROCESSORS_ONLN));
}

void outputFileName() {
    printf("16. The file Name is INPUT-1-PA6.txt\n");
}

void outputStatData(){ // combined all these into function for simplicity
    struct stat st;
    stat("INPUT-1-PA6.txt", &st);
    printf("17. The device is : %d\n", st.st_dev);
    printf("18. The inode is : %llu\n", st.st_ino);
    printf("19. The file protection : %o\n", st.st_mode);
    printf("20. Owner’s user ID : %d\n", st.st_uid);
    printf("21. Owner’s group ID : %d\n", st.st_gid);
    printf("22. Owner’s effective user ID : %d\n", geteuid());
    printf("23. Size of INPUT-1-PA6.txt file : %lld bytes\n", st.st_size);
    printf("24. Block size of INPUT-1-PA6.txt file  %zu\n", (size_t) st.st_blksize);
    printf("25. Number of blocks allocated to INPUT-1-PA6.txt file : %lld\n", st.st_blocks);
}
void appendToFile2() {
    printf("26. New text is appended to INPUT-1-PA6.txt file.\n");
    FILE* fp;

    fp = fopen("INPUT-1-PA6.txt", "a");
    fprintf(fp, "last step.\n");

    fclose(fp);
}

void outputUsingCommandSys(){
    printf("27. Redisplaying the content of INPUT-1-PA6.txt file.\n");
    system("cat INPUT-1-PA6.txt");
}

void renameFile() {
    printf("28. Renamed The file to be INPUT-2-PA6.txt .\n");
    rename("INPUT-1-PA6.txt", "INPUT-2-PA6.txt");
}

void outputUsingCommandSys2(){
    printf("29. The content of the new INPUT-2-PA6.txt file :\n");
    system("cat INPUT-2-PA6.txt");
}

void copyFile() {
    printf("\n");
    FILE *in = fopen("INPUT-2-PA6.txt", "r");
    FILE *out = fopen("INPUT-3-PA6.txt", "w");
    if (in != NULL && out != NULL) {
        char c;
        while ((c = fgetc(in)) != EOF) {
            if (c >= 'a' && c<= 'z') {
                c = c - 'a' + 'A';
            } else if (c >= 'A' && c<= 'Z') {
                c = c - 'A' + 'a';
            }
            fputc(c, out);
        }
        fclose(in);
        fclose(out);
    }
}

void outputCopy() {
    printf("30. The content of the new INPUT-3-PA6.txt file :\n");
    system("cat INPUT-3-PA6.txt");
}

void removeFile() {
    printf("31. Removed INPUT-3-PA6txt files from current Directory.\n");
    remove("INPUT-3-PA6.txt");
}

void outputDeletedFile() {
    printf("32. Displaying the content of INPUT-3-PA6.txt file.\n");
    system("cat INPUT-3-PA6.txt");
}

int main() {
    printf("System / File Manipulation Program\n\n");
    createInputFile();
    filePermissionsBefore();
    changeFileMode();
    filePermissionsAfter();
    appendText();
    outputContent();
    outputCurrentDateTime();
    outputLastAccess();
    outputSystemName();
    outputLocalHostName();
    outputHostName();
    outputProcessID();
    outputParentProcessID();
    outputProcessPriority();
    outputFileName();
    outputStatData();
    appendToFile2();
    outputUsingCommandSys();
    renameFile();
    outputUsingCommandSys2();
    copyFile();
    outputCopy();
    removeFile();
    outputDeletedFile();
    printf("\nApril-2023\nYuvanesh Rajamani");
    return 0;
}