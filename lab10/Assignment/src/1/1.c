
#include "linkedlist.h"
// TODO: Include the linkedlist header

// TODO: Include appopriate header file for dynamic memory allocation

int main()
{
        int num;
        char op[2];
        Node* head = NULL;


        // Illustration of various options available as example
        // i 10 (insert 10) at the head of the list
        // s 8 (search for 8 in the list, prints True/False
        // d 8 (deletes 8 if present in the list)
        // r -1 (reverse the entire list, second arg is ignored)
        // p -1 (print the list, the second arg is ignored)
        // q -1 (program exists, the second arg is ignored)

        
        do {
                scanf("%s %d", op, &num);

                switch(op[0]){
                    case 'i':
                      insert(&head, num);
                      break;

                    case 's':
                      if(search(head, num)){
                        printf("True\n");
                      }else{
                        printf("False\n");
                      }
                      break;

                   case 'd':
                      if(delete(&head, num)){
                        printf("Deleted\n");
                      }else{
                        printf("Failed\n");
		      }
                      break;

                    case 'r':
                    reverse(&head);
                      break;

                    case 'p':
                      print(head);
                      break;

                    case 'q':
                      // do ... while check will exit
                      // Do nothing
                      break;

                    default:
                      // Invalid option. 
                      printf("Invalid op %s\n", op); 
                      break;
		}
        }while(op[0] != 'q');

	// END	
        
        // TODO: Write appropriate code to free up memory allocated for
        // creating linked list


	//Do not add/modify anything below this line
	return 0;
}
