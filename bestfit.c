#include <stdio.h>

#define max 25

void main() {
    int frag[max], b[max], f[max], bf[max], ff[max];
    int i, j, nb, nf, temp;

    printf("\n\tMemory Management Scheme - First Fit\n");

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
        bf[i] = 0; // Initialize all blocks as free initially
    }

    printf("\nEnter the size of the files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    for (i = 1; i <= nf; i++) {
        for (j = 1; j <= nb; j++) {
            if (bf[j] == 0 && b[j] >= f[i]) { // Check if block is free and has enough size
                ff[i] = j;
                frag[i] = b[j] - f[i];
                bf[j] = 1; // Mark block as allocated
                break;
            }
        }
    }

    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment\n");
    for (i = 1; i <= nf; i++) {
        printf("%d\t\t%d\t\t", i, f[i]);
        if (bf[i] == 1) {
            printf("%d\t\t%d\t\t%d\n", ff[i], b[ff[i]], frag[i]);
        } else {
            printf("Not Allocated\n");
        }
    }
}
