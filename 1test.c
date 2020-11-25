#include<stdio.h>
/////////////////////////////////////////////////////////////////////////////////////
//Difference function
int difference(int arr1[], int arr2[], int output[], int len1, int len2) {
	int i, j, l=0;

	//arr1 = 1 2 3 4 5
	//arr2 = 3 4 5 6 7
	//difference = 1 2

	for(i=0; i<len1; i++) {
		for(j=0; j<len2; j++) {
			if(arr1[i]==arr2[j])
				break;
		/*if element of array1 is equal to element of array2
		  loop breaks, thus j will not be equal to len2*/
		}

		if(j==len2) {
		/*if j is equal to len2, then no element was equal, thus
		 it is required element of output*/
	  		 output[l] = arr1[i];
			l++;
		/*l will increment and will indicate number
		  number of elements in output.*/

		}
	}

	return l;

}//End of difference

/////////////////////////////////////////////////////////////////////////////////////

//Symmetric Difference
int sydif(int arr1[], int arr2[], int output[], int len1, int len2) {
	int i, j, l=0;

	//arr1 = 1 2 3 4 5
	//arr2 = 4 5 6 7 8
	//output = 1 2 3 6 7 8

	//Loop function similar to loop in difference
	for(i=0; i<len1; i++) {
		for(j=0; j<len2; j++) {
			if(arr1[i]==arr2[j])
				break;
		}
		if(j==len2) {
			output[l] = arr1[i];
			l++;
		}
	}


	//Loop function similar to loop in difference
	for(i=0; i<len1; i++) {
		for(j=0; j<len2; j++) {
			if(arr2[i]==arr1[j])
				break;
		}
		if(j==len2) {
			output[l] = arr2[i];
			l++;
		}
	}

	return l;
}//End of symmetric difference

/////////////////////////////////////////////////////////////////////////////////////

//Accept
void accept(int arr[], int size) {
	int i;
	for(i=0; i<size; i++) {
		scanf("%d", &arr[i]);
	}
}//End of accept

/////////////////////////////////////////////////////////////////////////////////////

//Union function
int uni(int arr1[], int arr2[], int output[], int len1, int len2) {
	int i, j, l=0;

	//arr1 = 1 2 3 4 5
	//arr2 = 4 5 6 7 8
	//output = 1 2 3 4 5 6 7 8

	for(i=0; i<len1; i++) {
		output[l] = arr1[i];
		l++;
	}

	for(i=0; i<len2; i++) {
		for(j=0; j<len1; j++) {
			if(arr2[i]==arr1[j])
				break;
		}
		if(j==len1) {
			output[l] = arr2[i];
			l++;
		}
	}

	return l;
}//End of union

/////////////////////////////////////////////////////////////////////////////////////

//Intersection
int inter(int arr1[], int arr2[], int output[], int len1, int len2) {
	int i, j, l=0;

	//arr1 = 1 2 3 4 5
        //arr2 = 4 5 6 7 8
        //output = 3 4

	for(i=0; i<len1; i++) {
		for(j=0; j<len2; j++) {
			if(arr1[i]==arr2[j]) {
				output[l] = arr1[i];
				l++;
				break;
			}
		}
	}

	return l;
}//End of intersection

/////////////////////////////////////////////////////////////////////////////////////

//display
void display(int output[], int l) {
	int i;
	for(i=0; i<l; i++) {
		if(i==l-1)
			printf("%d}\n", output[i]);
		else
			printf("%d,", output[i]);
	}
}//End of display

/////////////////////////////////////////////////////////////////////////////////////

//Repeat function
int repeat(int arr1[], int s1) {
	int i, j;
	for(i=0; i<s1; i++) {
		for(j=i+1; j<s1; j++) {
			if(arr1[i] == arr1[j]) {
				return 1;
				break;
			}
		}
	}

	return 0;
}//End of repeat

/////////////////////////////////////////////////////////////////////////////////////

//Main function
int main() {

	int arr1[20], arr2[20], output[40];
	//array1, array2, array of outputs
	int len1;//Size of array1
	int len2;//Size of array2
	int rval;//to return value of functions
	int again=1;//to repeat functions
	int menu;//for menu options

	while(again==1) {

		while(1) {

			printf("Enter size of the Set A(max 20): ");
			scanf("%d", &len1);
			printf("Enter size of the Set B(max 20): ");
			scanf("%d", &len2);
			printf("Enter values of Set A: ");
			accept(arr1, len1);//Accepting array 1
			printf("Enter values of Set B: ");
			accept(arr2, len2);//Accepting array 2

			//if any element of any array is repeated, repeat function will
			//return 1, thus the below condition will become true and elements
			//will be accepted again...
			if( repeat(arr1, len1)&&repeat(arr2, len2) ) {
				printf("\nElements repeated. Please re-enter elements in sets...\n");
				continue;
			}

			//if elements arent repeated, above if condition isnt executed and the loop breaks
			break;
		}

		printf("\n1.Difference\n2.Symmetric Difference\n3.Union\nIntersection\nPlease enter your choice: ");
		scanf("%d", &menu);

		switch(menu) {
			case 1: //length of output array is returned by functions
				//rval stores this returned value
				rval =  difference(arr1, arr2, output, len1, len2);
				printf("\nDifference is (Set A - Set B): {");
				display(output, rval);
				break;

			case 2: rval = sydif(arr1, arr2, output, len1, len2);
				printf("\nSymmetric Difference is: {");
				display(output, rval);
				break;

			case 3: rval = uni(arr1, arr2, output, len1, len2);
				printf("\nUnion is: {");
		        	display(output, rval);
				break;

			case 4: rval = inter(arr1, arr2, output, len1, len2);
				printf("\nIntersection is: {");
				display(output, rval);
				break;
		}

		printf("\nDo you want to continue with program?\n1.Yes\n2.No\nPlease enter your choice: ");
		scanf("%d", &again);
	}

	printf("\n");

	return 0;

}//End of main
