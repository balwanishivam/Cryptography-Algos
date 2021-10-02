//Submitted by Shivam Balwani
//ID:201851122
//Batch:CS
//Code:Caesar Cipher
#include <stdio.h>

char *encrypt(char *message, int key)
{
	int i;
	char ch;
	for (i = 0; message[i] != '\0'; ++i)
	{
		ch = message[i];

		if (ch >= 'a' && ch <= 'z')
		{
			ch = (ch + key - 97) % 26 + 97;
			message[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			ch = (ch + key - 65) % 26 + 65;
			message[i] = ch;
		}
	}
	return message;
}

char *decrypt(char *message, int key)
{
	int i;
	char ch;
	char *msg;
	for (i = 0; message[i] != '\0'; ++i)
	{
		ch = message[i];

		if (ch >= 'a' && ch <= 'z')
		{
			ch = (ch - key - 97 + 26) % 26 + 97;
			message[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			ch = (ch - key - 65 + 26) % 26 + 65;
			message[i] = ch;
		}
	}
	return message;
}

int main()
{
	// char enc_message[100];
	char *enc_message;
	int i, key;
	char message[] = "CRYPTO";
	// printf("Enter a message to encrypt: ");
	// gets(enc_message);
	printf("Enter key: ");
	scanf("%d", &key);

	enc_message = encrypt(message, key);
	printf("Encrypted message: %s", enc_message);
	// for (key = 1; key < 26; key++)
	// {
	// 	char enc_message[] = "AFITIFWF ";
	// 	printf("Encrypted message: %s", enc_message);
	// 	de_message = decrypt(enc_message, key);
	// 	printf("\nDecrypted message and key: %s %d \n", de_message, key);
	// }
	return 0;
}