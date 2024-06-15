/* 209488717 Tslil Sardam
 315636753 Ohad Adi */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* structures */
typedef struct student {
    char *name;
    int  id;
    struct clist *courses;
} student;

typedef struct course {
    char *title;
    int  number;
    struct slist *students;
} course;

typedef struct slist {
    student      *info;
    struct slist *next;
} slist;

typedef struct clist {
    course       *info;
    struct clist *next;
} clist;


/* prototypes */
slist* add_student(slist *students, char *name, int id);
clist* add_course(clist *courses, char *title, int number);
void reg_student(slist *students, clist *courses, int id, int number);
void unreg_student(slist *students, int id, int number);
void print_students(slist *students);
void print_courses(clist *courses);
void free_all(slist *sl, clist *cl);


/*DO NOT TOUCH THIS FUNCTION */
static void getstring(char *buf, int length) {
    int len;
    buf = fgets(buf, length, stdin);
    len = (int) strlen(buf);
    if (buf[len-1] == '\n')
        buf[len-1] = '\0';
}

/*DO NOT TOUCH THIS FUNCTION */
int main() {
    slist* students = 0;
	clist* courses = 0;
    char  c;
    char  buf[100];
    int   id, num;

    do {
        printf("Choose:\n"
               "    add (s)tudent\n"
               "    add (c)ourse\n"
               "    (r)egister student\n"
               "    (u)nregister student\n"
			   "    (p)rint lists\n"
               "    (q)uit\n");

        while ((c = (char) getchar()) == '\n');
        getchar();

        switch (c) {
        case 's':
            printf("Adding new student.\n");

            printf("Student name: ");
            getstring(buf, 100);

            printf("Student ID: ");
            scanf("%d", &id);

           students = add_student(students, buf, id);

            break;

        case 'c':
            printf("Adding new course.\n");

            printf("Course name: ");
            getstring(buf, 100);

            printf("Course number: ");
            scanf("%d", &num);

            courses = add_course(courses, buf, num);

            break;

        case 'r':
            printf("Registering a student to a course.\n");

            printf("Student ID: ");
            scanf("%d", &id);

            printf("Course number: ");
            scanf("%d", &num);

            reg_student(students, courses, id, num);

            break;

        case 'u':
            printf("Unregistering a student from a course.\n");

            printf("Student ID: ");
            scanf("%d", &id);

            printf("Course number: ");
            scanf("%d", &num);

            unreg_student(students, id, num);

            break;

        case 'p':
            printf("Printing Information.\n");

			print_students(students);
			print_courses(courses);

            break;

        case 'q':
			printf("Quitting...\n");
            break;
        }

        if (c != 'q')
            printf("\n");
    } while (c != 'q');

	free_all(students,courses);
    return 0;
}


slist* add_student(slist *students, char *name, int id) {
    char *std_name;
    slist *std_node, *currItem;
    std_node = (slist*) malloc(sizeof(slist));
    student *std;
    std = (student*) malloc(sizeof(student));
    if (std_node == NULL){
        /* printf("Memory allocation error!\n"); */
        exit(1);
    }
    if (std == NULL){
        /* printf("Memory allocation error!\n"); */
        exit(1);
    }

    /* creating student */
    std_name = (char*) malloc(sizeof(char) * 100);
    strcpy(std_name, name);
    std->name = std_name;
    std->id = id;
    std->courses = NULL;


    if (students == 0) {
        students = std_node;
        /* creating slist */
        students->info = std;
        students->next = NULL;
        return  students;
    }

    /* creating std node */
    std_node->info = std;
    std_node->next = NULL;

    /* if new students is smaller than the head */
    if (students->info->id > id){
        std_node->next = students;
        students = std_node;
        return students;
    }

    /* insert student in the correct place */
    currItem = students;
    while(currItem->next){
        if (currItem->info->id < id && currItem->next->info->id > id){
            std_node->next = currItem->next;
            currItem->next = std_node;
            return students;
        }
        else
            currItem = currItem->next;
    }

    /* insert student in the last place */
    std_node->next = NULL;
    currItem->next = std_node;
    return students;
}

clist* add_course(clist *courses, char *title, int number){
    char *course_name;
    clist *crs_node, *currItem;
    crs_node = (clist*) malloc(sizeof(clist));
    course *crs;
    crs = (course*) malloc(sizeof(course));

    if (crs_node == NULL){
        /* printf("Memory allocation error!\n"); */
        exit(1);
    }
    if (crs == NULL){
        /* printf("Memory allocation error!\n"); */
        exit(1);
    }

    /* creating course */
    course_name = (char*) malloc(sizeof(char) * 100);
    strcpy(course_name, title);
    crs->title = course_name;
    crs->number = number;
    crs->students = NULL;


    if (courses == 0) {
        courses = crs_node;
        /* creating clist */
        courses->info = crs;
        courses->next = NULL;
        return  courses;
    }

    /* creating std node */
    crs_node->info = crs;
    crs_node->next = NULL;

    /* if new course number is smaller than the head */
    if (courses->info->number > number){
        crs_node->next = courses;
        courses = crs_node;
        return courses;
    }

    /* insert course in the correct place */
    currItem = courses;
    while(currItem->next){
        if (currItem->info->number < number && currItem->next->info->number > number){
            crs_node->next = currItem->next;
            currItem->next = crs_node;
            return courses;
        }
        else
            currItem = currItem->next;
    }

    /* insert course in the last place */
    crs_node->next = NULL;
    currItem->next = crs_node;
    return courses;
}

void reg_student(slist *students, clist *courses, int id, int number){
    student *std;
    course  *crs;
    clist *curr_crs, *new_ncrs, *currItem;
    slist *curr_std, *new_nstd ,*currStd;
    std = NULL;
    /* find the course in the courses list */
    curr_crs = courses;

    while(curr_crs){
        if(curr_crs->info->number == number){
          crs = curr_crs->info;
          break;
        }
        else{
            curr_crs = curr_crs->next;
        }
    }

    /* find the student in the students list */
    curr_std = students;
    while(curr_std){
        if(curr_std->info->id == id){
            std = curr_std->info;
            break;
        }
        else{
            curr_std = curr_std->next;
        }
    }

    /* Insert course to student list course */
    new_ncrs = (clist*) malloc(sizeof (clist));
    new_ncrs->info = crs;
    currItem = std->courses;
    /* First node*/
    if(!currItem){
        std->courses = new_ncrs;
        std->courses->next = NULL;
    }
    /* New head */
    if ( currItem && currItem->info->number > number){
        new_ncrs->next = std->courses;
        std->courses = new_ncrs;
        currItem = NULL;
    }

    /* Rest of case */
    while(currItem){
        /* Tail */
        if(currItem->info->number < number && (!currItem->next)) {
            new_ncrs->next = currItem->next;
            currItem->next = new_ncrs;
            break;
        }

        if (currItem->info->number < number && currItem->next->info->number > number){
            new_ncrs->next = currItem->next;
            currItem->next = new_ncrs;
            break;
        }

        currItem = currItem->next;
    }


    /* insert student to the course list of students */
    new_nstd = (slist*) malloc(sizeof (slist));
    new_nstd->info = std;
    currStd = crs->students;
    /* First node*/
    if(!currStd){
        crs->students = new_nstd;
        crs->students->next = NULL;
    }
    /* New head */
    if(currStd && currStd->info->id > id){
        new_nstd->next = crs->students;
        crs->students = new_nstd;
        currStd = NULL;
    }
    /* Rest of case */
    while(currStd){
        /* Tail */
        if(currStd->info->id < id && (!currStd->next)) {
            new_nstd->next = currStd->next;
            currStd->next = new_nstd;
            break;
        }
        if (currStd->info->id < id && currStd->next->info->id > id){
            new_nstd->next = currStd->next;
            currStd->next = new_nstd;
            break;
        }
        currStd = currStd->next;
    }
}

void unreg_student(slist *students, int id, int number){
    student *std;
    course  *crs;
    slist *curr_std, *prev_std, *crs_std_list;
    clist *std_crs_list, *prev_crs;
    std = NULL;

    /* find the student in the students list */
    curr_std = students;
    while(curr_std){
        if(curr_std->info->id == id){
            std = curr_std->info;
            break;
        }
        else{
            curr_std = curr_std->next;
        }
    }

    /* find the course in the student courses list */
    std_crs_list = std->courses;
    prev_crs = NULL;

    while (std_crs_list->next){
        if(std_crs_list->info->number == number){
            crs = std_crs_list->info;
            break;
        }
        else{
            prev_crs = std_crs_list;
            std_crs_list = std_crs_list->next;
        }
    }

    /* solve problem for the tail */
    if(!(std_crs_list->next)){
        if(std_crs_list->info->number == number) {
            crs = std_crs_list->info;
        }
    }

    /* Remove the node of the course from the student courses list*/
    if(prev_crs){
        prev_crs->next = std_crs_list->next;
    }
    else{
        std->courses = std_crs_list ->next;
    }
    free(std_crs_list);

    /* Remove the node of student from the course students list */
    crs_std_list = crs->students;
    prev_std = NULL;
    while(crs_std_list->next){
        if(crs_std_list->info->id == id){
            break;
        }
        else{
            prev_std = crs_std_list;
            crs_std_list = crs_std_list->next;
        }
    }

    if(prev_std){
        prev_std->next = crs_std_list->next;
    }
    else{
        crs->students = crs_std_list->next;
    }
    free(crs_std_list);

}
void print_students(slist *students){
    slist *curr_std;
    clist *curr_crs;
    curr_std = students;
    printf("STUDENT LIST:\n");
    while(curr_std) {
        printf("%d:%s\n", curr_std->info->id, curr_std->info->name);
        curr_crs = curr_std->info->courses;
        if (curr_crs) {
            printf("courses:");
            while (curr_crs->next) {
                printf(" %d-%s,", curr_crs->info->number, curr_crs->info->title);
                curr_crs = curr_crs->next;
            }
            printf(" %d-%s\n", curr_crs->info->number, curr_crs->info->title);
        }
        else{
            printf("student is not registered for courses.\n");
        }
        curr_std = curr_std->next;
    }
}
void print_courses(clist *courses){
    slist *curr_std;
    clist *curr_crs;
    curr_crs = courses;
    printf("COURSE LIST:\n");
    while (curr_crs){
        printf("%d:%s\n", curr_crs->info->number, curr_crs->info->title);
        curr_std = curr_crs->info->students;
        if(curr_std) {
            printf("students:");
            while (curr_std->next) {
                printf(" %d-%s,", curr_std->info->id, curr_std->info->name);
                curr_std = curr_std->next;
            }
            printf(" %d-%s\n", curr_std->info->id, curr_std->info->name);
        }
        else{
            printf("course has no students.\n");
        }
        curr_crs = curr_crs->next;
    }
}
void free_all(slist *sl, clist *cl){
    slist *curr_std, *temp_std;
    clist *curr_crs, *temp_crs;
    curr_std = sl;
    /* Releasing student lists and their courses */
    while(curr_std){
        curr_crs = curr_std->info->courses;
        while(curr_crs){
            temp_crs = curr_crs;
            curr_crs = curr_crs->next;
            free(temp_crs);
        }
        temp_std = curr_std;
        curr_std = curr_std->next;
	    free(temp_std->info->name);
        free(temp_std->info);
        free(temp_std);
    }

    curr_crs = cl;
    /* Releasing courses lists and their students*/
    while(curr_crs){
        curr_std = curr_crs->info->students;
        while(curr_std){
            temp_std = curr_std;
            curr_std = curr_std->next;
            free(temp_std);
        }
        temp_crs = curr_crs;
        curr_crs = curr_crs->next;
	    free(temp_crs->info->title);
        free(temp_crs->info);
        free(temp_crs);
    }
}