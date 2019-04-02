#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include <string.h>

#define ALL 	(1<<0)
#define LIST 	(1<<1)
#define INODE	(1<<2)
#define RECUR	(1<<3)



void handle_options(int argc, char** argv, int* flag);
void print_time();
void file_type(char* perm, struct stat buf);
void file_perm(char* perm, struct stat buf);


void print_ls(int, char**);
void print_list(char*);
void print_all();
void print_recur(char*);
void print_inode();



int main(int argc, char** argv) {
	int flag = 0;

	handle_options(argc, argv, &flag);

	if (flag & ALL) {
	
	}

	if (flag & LIST)  {

	}

	if (flag & INODE) {

	}

	if (flag & RECUR) {

	}


	print_ls(argc, argv);

	//print_list(argc, argv);

	printf("\n");

	print_recur(".");
	return 0;
}


void print_ls(int argc, char** argv) {
	DIR* dp;
	struct dirent *p;
	struct stat buf;

	dp = opendir(".");
	while(p = readdir(dp)) {
		//printf("%s ", p->d_name);
		print_list(p->d_name);
	}
	printf("\n");
}


void print_list(char* fname) {
	struct stat buf;
	struct passwd* pwd;
	struct group* grp; 
	
	char perm[11] = "----------";

	stat(fname, &buf);

	file_perm(perm, buf);
	file_type(perm, buf);

	printf("%s ", perm);
	printf("%d ", buf.st_nlink);

	pwd = getpwuid(buf.st_uid);
	printf("%s ", pwd->pw_name);

	grp = getgrgid(buf.st_gid);
	printf("%s ", grp->gr_name);

	printf("%d ", buf.st_size);

	print_time();

	printf("%s \n", fname);
}

void print_all() {

}

void print_recur(char* dname) {
	DIR* dp;
	struct dirent *p;
	struct stat buf;

	chdir(dname);
	dp = opendir(".");
	printf("%s : ", dname);
	while(p = readdir(dp))
		printf("%s ", p->d_name);
	printf("\n\n");

	rewinddir(dp);
	while(p = readdir(dp)) {
		lstat(p->d_name, &buf);
		if (S_ISDIR(buf.st_mode))
			if (strcmp(p->d_name, ".") && strcmp(p->d_name, ".."))
				print_recur(p->d_name);
	}
	closedir(dp);
	chdir("..");
}



void print_inode() {

}



void print_time() {
	time_t now;
	char *str;
	struct tm* l_time;
	char mon[][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

	now = time(0);
	l_time = localtime(&now);
	printf("%s %d %d:%d ", mon[l_time->tm_mon], l_time->tm_mday, l_time->tm_hour, l_time->tm_min);
}


void handle_options(int argc, char** argv, int* flag) {
	int ch;
	while ((ch = getopt(argc, argv, "ailR")) != -1) {
		switch (ch) {
		case 'a': *flag |= ALL; break;
		case 'l': *flag |= LIST; break;
		case 'i': *flag |= INODE; break;
		case 'R': *flag |= RECUR; break;
		}
	}
}


void file_perm(char* perm, struct stat buf) {
	int i = 0;
	char rwx[] = "rwx";

	for (i = 0; i < 9; i++) {
		if ((buf.st_mode >> (8-i)) & 1) {
			perm[1 + i] = rwx[i % 3];
		}
	}

	for (i = 0; i < 3; i++) {
		if(((buf.st_mode >> (11 - i)) & 1) && ((buf.st_mode >> (6 - i*3)) ^ 1)) {
			perm[(i + 1) * 3] = 'S';
		} if(((buf.st_mode >> (11 - i)) & 1) && ((buf.st_mode >> (6 - i*3)) & 1)) {
			perm[(i + 1) * 3] = 's';
		}
	}
}

void file_type(char* perm, struct stat buf) {
	if(S_ISREG(buf.st_mode)) perm[0] = '-';
	if(S_ISDIR(buf.st_mode)) perm[0] = 'd';
	if(S_ISCHR(buf.st_mode)) perm[0] = 'c';
	if(S_ISBLK(buf.st_mode)) perm[0] = 'b';
	if(S_ISFIFO(buf.st_mode)) perm[0] = 'f';
	if(S_ISLNK(buf.st_mode)) perm[0] = 'l';
	if(S_ISSOCK(buf.st_mode)) perm[0] = 's';
}
