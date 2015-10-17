#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libDico.h"

int main(int argc, char const *argv[])
{
	Dictionary dico = createDictionary();
	dico = createLetter('A');
	dico->leftSon = createLetter('*');
	
	Word newWord = "Bateau";
	Word starWord = malloc(strlen(newWord) + 2);
	strcpy(starWord, newWord);
	strcat(starWord, "*");

	if(! wordBelongs(dico, newWord)) {
		dico = addWordRecursive(dico, starWord, 0);
	}
	
	printf("\nAfter adding the word :\n");
	if(wordBelongs(dico, newWord)) {
		printf("\t\"%s\" belongs to dico !\n", newWord);
	} else {
		printf("\t\"%s\" doesn't belong to dico\n", newWord);
	}

	addWordRecursive(dico, "Batiment*", 0);

	printf("\n\nDisplaying dictionary : \n\n");
	displayDico(dico, "");

	/*
	if(wordBelongs(dico, newWord)) {
		dico = deleteWordRecursive(dico, starWord, strlen(starWord));
	}
	
	printf("\nAfter deleting the word :\n");
	if(wordBelongs(dico, newWord)) {
		printf("\t\"%s\" belongs to dico !", newWord);
	} else {
		printf("\t\"%s\" doesn't belong to dico", newWord);
	}
	*/

	printf("\n");

	return 0;
}