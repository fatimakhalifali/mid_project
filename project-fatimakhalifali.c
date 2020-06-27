#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#pragma warning(disable : 4996)
#define N 100
#define L 20

char full_name[L][N] = { "Fatima_Khalifali", "Tahir_Khalifali", "Fikrat_Khalifali", "Aynur_Khalifali", "Amina_Mammadova", "Rafiga_Huseynova", "Latif_Huseynov", "Aylin_Mammadova", "Ramiza_Hummatli", "Huseyn_Gahramanov" };
char phone_number[L][N] = { "+994519553300", "+994519552200", "+994502327282", "+99450337979", "+994505302002", "+994503368191", "+995503368778", "+994703503050", "+994554107845", "+99470458999" };
char e_mail[L][N] = { "fatya.khalifali@gmail.com", "tahir@mail.ru", "f.khalifali1973@mail.ru", "aynur.khalifali@mail.ru", "amammadova@gmail.com", "rafiga1953@mail.ru", "latif1948@mail.ru", "ailin.mva@gmail.com", "ramiza.hummat@gmail.com", "hgahramanov2000@gmail.com" };
char contact_address[L][N] = { "42_Jafar_Khandan_Baku", "42_Jafar_Khandan_Baku", "73_Mirali_Gashgay_Baku", "73_Mirali_Gashgay_Baku", "41_Imran_Gasimov_Baku", "61_Hasan_Aliyev_Baku", "61_Hasan_Aliyev_Baku", "34_Tofig_Guliyev_Baku", "1_Jafar_Khandan_Baku", "3_Ibrahim_Dadashov_Baku" };
char work[L][N] = { "Student", "Student", "Manager", "Dentist", "Student", "Engineer", "Engineer", "Student", "Student", "Student" };
char relationship[L][N] = { "me" , "brother", "father", "mother", "cousin", "grandmother", "grandfather", "friend", "friend", "friend" };

int count = 10; //count contacts after test cases

void add_contact();
bool error_full_name(char full_name[L][N]);
bool error_phone_number(char phone_number[L][N]);
bool error_e_mail(char e_mail[L][N]);
bool error_address(char contact_address[L][N]);
bool error_work(char work[L][N]);
bool error_relationship(char relationship[L][N]);
void list_all();
void total_contact();
void search();
void delete();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	printf("                                                                                   **********************                                                                                           \n");
	printf("************************************************************************************ FATIMA'S PHONEBOOK ********************************************************************************************\n");
	printf("                                                                                   **********************                                                                                           \n\n");
	printf("\n");

	char operation_num;

	for (;;) {
		printf("                                                                                  ************************\n");
		printf("                                                                                  | 1 | Add Contact\n");
		printf("                                                                                  | 2 | List All Contacts\n");
		printf("                                                                                  | 3 | Total Contacts\n");
		printf("                                                                                  | 4 | Search\n");
		printf("                                                                                  | 5 | Delete\n");
		printf("                                                                                  | 6 | Quit\n");
		printf("                                                                                  ************************\n\n");

		printf("\t\t\t\t\t\t\t\t\t\t  Enter operation number: ");
		scanf("%c", &operation_num);

		switch (operation_num) {
		case '1':
			add_contact();
			break;
		case '2':
			list_all();
			break;
		case '3':
			total_contact();
			break;
		case '4':
			search();
			break;
		case '5':
			delete();
			break;
		case '6':
			return 0;
		default:
			printf("\n\t\t\t\t\t\t\t\t\t\t  Invalid input. See the menu and enter again.\n");
		}
		printf("\n");

		while (getchar() != '\n');
	}
}

////////////////////////////////////////////////////////////// ADD CONTACT FUNCTION /////////////////////////////////////////////////////////////////////////

void add_contact() {
	printf("\t\t\t\t\t\t\t\t\t\t  Enter contact's full name: ");
	scanf("%s", &full_name[count]);
	while (error_full_name(full_name[count]) == false) {
		printf("\n\t\t\t\t\t\t\t\t\t\t  * Name must contain ONLY letters and an underscore in the middle (firstName_lastName).\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t  Enter again: ");
		scanf("%s", &full_name[count]);
	}

	printf("\t\t\t\t\t\t\t\t\t\t  Enter contact's phone number: ");
	scanf("%s", &phone_number[count]);
	while (error_phone_number(phone_number[count]) == false) {
		printf("\n\t\t\t\t\t\t\t\t\t\t  * Phone number must contain ONLY numbers and (optional) plus sign at the beginning.\n");
		printf("\t\t\t\t\t\t\t\t\t\t  * Phone number must have AT LEAST 7 digits.\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t  Enter again: ");
		scanf("%s", &phone_number[count]);
	}

	printf("\t\t\t\t\t\t\t\t\t\t  Enter contact's e-mail: ");
	scanf("%s", &e_mail[count]);
	while (error_e_mail(e_mail[count]) == false) {
		printf("\n\t\t\t\t\t\t\t\t\t\t  * E-mail must start ONLY with a letter or number.\n");
		printf("\t\t\t\t\t\t\t\t\t\t  * E-mail prefix must have AT LEAST 2 characters.\n");
		printf("\t\t\t\t\t\t\t\t\t\t  * E-mail prefix must contain ONLY letters, numbers, underscore and dot.\n");
		printf("\t\t\t\t\t\t\t\t\t\t  * Do not forget to put '@' before e-mail domain.\n");
		printf("\t\t\t\t\t\t\t\t\t\t  * E-mail must have valid e-mail domain (try either mail.ru or gmail.com).\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t  Enter again: ");
		scanf("%s", &e_mail[count]);
	}

	printf("\t\t\t\t\t\t\t\t\t\t  Enter contact's address: ");
	scanf("%s", &contact_address[count]);
	while (error_address(contact_address[count]) == false) {
		printf("\n\t\t\t\t\t\t\t\t\t\t  * Address must contain ONLY letters, numbers and underscores in the middle (streetNumber_streetName_cityName).\n");
		printf("\t\t\t\t\t\t\t\t\t\t  * The numbers can only be provided at the very BEGINNING, before the first underscore.\n");
		printf("\t\t\t\t\t\t\t\t\t\t  * It is OKAY if street number is not provided.\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t  Enter again: ");
		scanf("%s", &contact_address[count]);
	}

	printf("\t\t\t\t\t\t\t\t\t\t  Enter contact's job: ");
	scanf("%s", &work[count]);
	while (error_work(work[count]) == false) {
		printf("\n\t\t\t\t\t\t\t\t\t\t  * Job must contain ONLY letters.\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t  Enter again: ");
		scanf("%s", &work[count]);
	}

	printf("\t\t\t\t\t\t\t\t\t\t  Enter your relationship to the contact: ");
	scanf("%s", &relationship[count]);
	while (error_relationship(relationship[count]) == false) {
		printf("\n\t\t\t\t\t\t\t\t\t\t  * Relationship must contain ONLY letters.\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t  Enter again: ");
		scanf("%s", &relationship[count]);
	}

	count++;
}

///////////////////////////////////////////////////////////////// ERROR HANDLING FUNCTIONS /////////////////////////////////////////////////////////////////

/*************************************************************** ERROR HANDLING FOR FULL NAME *************************************************************/

bool error_full_name(char full_name[L][N]) {
	int count_underscore = 0;

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < strlen(full_name[i]); j++)
		{
			if (isalpha(full_name[0][0])) {
				if (full_name[i][j] == '_' && j != strlen(full_name[i]) - 1) {
					++count_underscore;
				}
			}
		}

	}

	if (count_underscore == 1) {
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; full_name[i][j] != '\0'; j++)
			{
				if (!isalpha(full_name[i][j]) && full_name[i][j] != '_') {
					return false;
				}
			}
		}
	}
	else if (count_underscore != 1) {
		return false;
	}
	return true;
}

/************************************************************* ERROR HANDLING FOR PHONE NUMBER *************************************************************/

bool error_phone_number(char phone_number[L][N]) {
	int count_digit = 0;

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; phone_number[i][j] != '\0'; j++)
		{
			++count_digit;
		}
	}

	if (phone_number[0][0] == '+') {
		for (int i = 0; i < 1; i++)
		{
			for (int j = 1; j < strlen(phone_number[i]); j++)
			{
				if (!(phone_number[i][j] >= '0' && phone_number[i][j] <= '9' && count_digit > 6)) {
					return false;
				}
			}
		}
	}
	else if (phone_number[0][0] >= '0' && phone_number[0][0] <= '9') {
		for (int i = 0; i < 1; i++)
		{
			for (int j = 1; j < strlen(phone_number[i]); j++)
			{
				if (!(phone_number[i][j] >= '0' && phone_number[i][j] <= '9' && count_digit > 6)) {
					return false;
				}
			}
		}
	}
	else if (!(phone_number[0][0] >= '0' && phone_number[0][0] <= '9')) {
		return false;
	}

	return true;
}

/************************************************************ ERROR HANDLING FOR E-MAIL *******************************************************************/

bool error_e_mail(char e_mail[L][N]) {
	for (int i = 0; i < 1; i++)
	{
		int count_prefix = 0;

		for (int j = 0; e_mail[i][j] != '@'; j++)
		{
			if (isalnum(e_mail[0][0])) {
				++count_prefix;
			}
		}

		for (int j = 0; e_mail[i][j] != '\0'; j++)
		{
			if (count_prefix >= 2) {
				if (strstr(e_mail[i], "@gmail.com")) {
					if (!((isalpha(e_mail[i][j])) || e_mail[i][j] == '_' || e_mail[i][j] == '.' || e_mail[i][j] == '@' || (e_mail[i][j] >= '0' && e_mail[i][j] <= '9'))) {
						return false;
					}
					else if (e_mail[i][j] == '@') {
						if (e_mail[i][j + 10] != '\0') {
							return false;
						}
					}
				}
				else if (strstr(e_mail[i], "@mail.ru")) {
					if (!((isalpha(e_mail[i][j])) || e_mail[i][j] == '_' || e_mail[i][j] == '.' || e_mail[i][j] == '@' || (e_mail[i][j] >= '0' && e_mail[i][j] <= '9'))) {
						return false;
					}
					else if (e_mail[i][j] == '@') {
						if (e_mail[i][j + 8] != '\0') {
							return false;
						}
					}

				}
				else if (!(strstr(e_mail[i], "@gmail.com") || strstr(e_mail[i], "@mail.ru"))) {
					return false;
				}
			}
			else if (count_prefix < 2) {
				return false;
			}
		}
	}
	return true;
}

/*********************************************************** ERROR HANDLING FOR ADDRESS *******************************************************************/

bool error_address(char contact_address[L][N]) {
	int count_underscore = 0;

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < strlen(contact_address[i]); j++)
		{
			if (isalpha(contact_address[0][0]) || (contact_address[0][0] >= '0' && contact_address[0][0] <= '9')) {
				if (contact_address[i][j] == '_' && j != strlen(contact_address[i]) - 1) {
					++count_underscore;
				}
			}
		}

	}

	int j;
	if (count_underscore >= 1) {
		for (int i = 0; i < 1; i++)
		{
			for (j = 0; contact_address[i][j] != '_'; j++)
			{
				if (!isdigit(contact_address[i][j]) && !isalpha(contact_address[i][j])) {
					return false;
				}
			}
			for (int z = j; contact_address[i][z] != '\0'; z++)
			{
				if (!isalpha(contact_address[i][z]) && contact_address[i][z] != '_') {
					return false;
				}
			}
		}
	}
	else if (count_underscore < 1) {
		return false;
	}
	return true;
}

/************************************************************ ERROR HANDLING FOR WORK *********************************************************************/

bool error_work(char work[L][N]) {
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < strlen(work[i]); j++)
		{
			if (!isalpha(work[i][j])) {
				return false;
			}
		}

		return true;
	}
}

/********************************************************* ERROR HANDLING FOR RELATIONSHIP ****************************************************************/

bool error_relationship(char relationship[L][N]) {
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < strlen(relationship[i]); j++)
		{
			if (!isalpha(relationship[i][j])) {
				return false;
			}
		}

		return true;
	}
}

////////////////////////////////////////////////////////////////// LIST ALL FUNCTION ////////////////////////////////////////////////////////////////////////

void list_all() {
	for (int i = 0; i < count; i++)
	{
		printf("\t\t\t\t\t\t\t\t\t\t  Contact's name: %s\n", full_name[i]);
		printf("\t\t\t\t\t\t\t\t\t\t  Contact's phone number: %s\n", phone_number[i]);
		printf("\t\t\t\t\t\t\t\t\t\t  Contact's e-mail: %s\n", e_mail[i]);
		printf("\t\t\t\t\t\t\t\t\t\t  Contact's address: %s\n", contact_address[i]);
		printf("\t\t\t\t\t\t\t\t\t\t  Contact's job: %s\n", work[i]);
		printf("\t\t\t\t\t\t\t\t\t\t  Contact's relationship to you: %s\n\n", relationship[i]);
	}
}

///////////////////////////////////////////////////////////////// SHOW TOTAL FUNCTION //////////////////////////////////////////////////////////////////////

void total_contact() {
	printf("\t\t\t\t\t\t\t\t\t\t  Total amount of contacts: %d\n", count);
}

/////////////////////////////////////////////////////////////////// SEARCH FUNCTION //////////////////////////////////////////////////////////////////////////

void search() {
	char contact_for_search[50];
	int i;
	printf("\t\t\t\t\t\t\t\t\t\t  Enter the full name, phone number or e-mail of the contact: ");
	scanf("%s", &contact_for_search);
	int j;
	for (i = 0; i < L; i++)
	{
		if (strcmp(contact_for_search, full_name[i]) == 0) {
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's phone number: %s\n", phone_number[i]);
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's e-mail: %s\n", e_mail[i]);
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's address: %s\n", contact_address[i]);
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's job: %s\n", work[i]);
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's relationship to you: %s\n\n", relationship[i]);
			break;
		}

		else if (strcmp(contact_for_search, phone_number[i]) == 0) {
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's full name: %s\n", full_name[i]);
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's e-mail: %s\n", e_mail[i]);
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's address: %s\n", contact_address[i]);
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's job: %s\n", work[i]);
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's relationship to you: %s\n\n", relationship[i]);
			break;
		}
		else if (strcmp(contact_for_search, e_mail[i]) == 0) {
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's full name: %s\n", full_name[i]);
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's phone_number: %s\n", phone_number[i]);
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's address: %s\n", contact_address[i]);
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's job: %s\n", work[i]);
			printf("\t\t\t\t\t\t\t\t\t\t  Contact's relationship to you: %s\n\n", relationship[i]);
			break;
		}
		else if (strcmp(contact_for_search, full_name[i]) != 0) {
			for (j = 0; contact_for_search[j] != '\0'; j++)
			{
				if (contact_for_search[j] - full_name[i][j] == 32 || full_name[i][j] - contact_for_search[j] == 32) {
					continue;
				}
				else if (contact_for_search[j] - full_name[i][j] == 0) {
					continue;
				}
				else {
					break;
				}
			}

			if (full_name[i][j] == '\0' && contact_for_search[j] == '\0') {
				printf("\t\t\t\t\t\t\t\t\t\t  Contact's phone number: %s\n", phone_number[i]);
				printf("\t\t\t\t\t\t\t\t\t\t  Contact's e-mail: %s\n", e_mail[i]);
				printf("\t\t\t\t\t\t\t\t\t\t  Contact's address: %s\n", contact_address[i]);
				printf("\t\t\t\t\t\t\t\t\t\t  Contact's job: %s\n", work[i]);
				printf("\t\t\t\t\t\t\t\t\t\t  Contact's relationship to you: %s\n\n", relationship[i]);
				break;
			}
			else if (i == L) {
				printf("\t\t\t\t\t\t\t\t\t\t  Contact NOT FOUND.\n\n");
				break;
			}

		}
	}

	if (i == L) {
		printf("\t\t\t\t\t\t\t\t\t\t  Contact NOT FOUND.\n\n");
	}
}

/////////////////////////////////////////////////////////////////// DELETE FUNCTION //////////////////////////////////////////////////////////////////////

void delete() {
	char contact_for_search[50];
	int i;
	printf("\t\t\t\t\t\t\t\t\t\t  Enter the full name, phone number or e-mail of the contact: ");
	scanf("%s", &contact_for_search);
	int j;
	for (i = 0; i < L; i++)
	{
		if (strcmp(contact_for_search, full_name[i]) == 0 || strcmp(contact_for_search, phone_number[i]) == 0 || strcmp(contact_for_search, e_mail[i]) == 0) {
			break;
		}
		else if (strcmp(contact_for_search, full_name[i]) != 0) {
			for (j = 0; contact_for_search[j] != '\0'; j++)
			{
				if (contact_for_search[j] - full_name[i][j] == 32 || full_name[i][j] - contact_for_search[j] == 32) {
					continue;
				}
				else if (contact_for_search[j] - full_name[i][j] == 0) {
					continue;
				}
				else {
					break;
				}
			}
			if (contact_for_search[j] == '\0' && full_name[i][j] == '\0') {
				break;
			}
		}
	}
	if (i == L) {
		printf("\t\t\t\t\t\t\t\t\t\t  Contact NOT FOUND.\n\n");
	}
	else if (i != L) {
		for (int place = i; place < L - 1; place++)
		{
			for (int j = 0; j < N; j++)
			{
				full_name[place][j] = full_name[place + 1][j];
				phone_number[place][j] = phone_number[place + 1][j];
				e_mail[place][j] = e_mail[place + 1][j];
				contact_address[place][j] = contact_address[place + 1][j];
				work[place][j] = work[place + 1][j];
				relationship[place][j] = relationship[place + 1][j];
			}
		}
		count--;
	}
}