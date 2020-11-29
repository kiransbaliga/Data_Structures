#include <stdio.h>

#include <stdlib.h>

struct tree

{

    int data;

    struct tree *left;

    struct tree *right;

} *root = NULL, *temp = NULL, *t2, *t1;

void deletion();

void insertion();

void delete ();

void inorder(struct tree *t);

void create();

void search(struct tree *t);

void preorder(struct tree *t);

void postorder(struct tree *t);

void searchpos(struct tree *t, int data);

int smallest(struct tree *t);

int largest(struct tree *t);

int flag = 1;

void main()

{

    int ch;

    printf("\n1 - Insert an element into tree\n");

    printf("2 - Delete an element from the tree\n");

    printf("3 - Inorder Traversal\n");

    printf("4 - Preorder Traversal\n");

    printf("5 - Postorder Traversal\n");

    printf("6 - Exit\n");

    while (1)

    {

        printf("\nEnter your choice : ");

        scanf("%d", &ch);

        switch (ch)

        {

        case 1:

            insertion();

            break;

        case 2:

            delete ();

            break;

        case 3:

            inorder(root);

            break;

        case 4:

            preorder(root);

            break;

        case 5:

            postorder(root);

            break;

        case 6:

            exit(0);

        default:

            printf("Wrong choice, Please enter correct choice  ");

            break;
        }
    }
}



void insertion()

{

    create();

    if (root == NULL)

        root = temp;

    else

        search(root);
}


void create()

{

    int data;

    printf("Enter data of node to be inserted : ");

    scanf("%d", &data);

    temp = (struct tree *)malloc(1 * sizeof(struct tree));

    temp->data = data;

    temp->left = temp->right = NULL;
}



void search(struct tree *t)

{

    if ((temp->data > t->data) && (t->right != NULL))

        search(t->right);

    else if ((temp->data > t->data) && (t->right == NULL))

        t->right = temp;

    else if ((temp->data < t->data) && (t->left != NULL)) 
        search(t->left);

    else if ((temp->data < t->data) && (t->left == NULL))

        t->left = temp;
}


void inorder(struct tree *t)

{

    if (root == NULL)

    {

        printf("No elements in a tree to display");

        return;
    }

    if (t->left != NULL)

        inorder(t->left);

    printf("%d -> ", t->data);

    if (t->right != NULL)

        inorder(t->right);
}


void delete ()

{

    int data;

    if (root == NULL)

    {

        printf("No elements in a tree to delete");

        return;
    }

    printf("Enter the data to be deleted : ");

    scanf("%d", &data);

    t1 = root;

    t2 = root;

    searchpos(root, data);
}


void preorder(struct tree *t)

{

    if (root == NULL)

    {

        printf("No elements in a tree to display");

        return;
    }

    printf("%d -> ", t->data);

    if (t->left != NULL)

        preorder(t->left);

    if (t->right != NULL)

        preorder(t->right);
}


void postorder(struct tree *t)

{

    if (root == NULL)

    {

        printf("No elements in a tree to display ");

        return;
    }

    if (t->left != NULL)

        postorder(t->left);

    if (t->right != NULL)

        postorder(t->right);

    printf("%d -> ", t->data);
}



void searchpos(struct tree *t, int data)

{

    if ((data > t->data))

    {

        t1 = t;

        searchpos(t->right, data);
    }

    else if ((data < t->data))

    {

        t1 = t;

        searchpos(t->left, data);
    }

    else if ((data == t->data))

    {

        deletion(t);
    }
}



void deletion(struct tree *t)

{

    int k;

    

    if ((t->left == NULL) && (t->right == NULL))

    {

        if (t1->left == t)

        {

            t1->left = NULL;
        }

        else

        {

            t1->right = NULL;
        }

        t = NULL;

        free(t);

        return;
    }

    

    else if ((t->right == NULL))

    {

        if (t1 == t)

        {

            root = t->left;

            t1 = root;
        }

        else if (t1->left == t)

        {

            t1->left = t->left;
        }

        else

        {

            t1->right = t->left;
        }

        t = NULL;

        free(t);

        return;
    }

  

    else if (t->left == NULL)

    {

        if (t1 == t)

        {

            root = t->right;

            t1 = root;
        }

        else if (t1->right == t)

            t1->right = t->right;

        else

            t1->left = t->right;

        t == NULL;

        free(t);

        return;
    }

    
    else if ((t->left != NULL) && (t->right != NULL))

    {

        t2 = root;

        if (t->right != NULL)

        {

            k = smallest(t->right);

            flag = 1;
        }

        else

        {

            k = largest(t->left);

            flag = 2;
        }

        searchpos(root, k);

        t->data = k;
    }
}

int smallest(struct tree *t)

{

    t2 = t;

    if (t->left != NULL)

    {

        t2 = t;

        return (smallest(t->left));
    }

    else

        return (t->data);
}

int largest(struct tree *t)

{

    if (t->right != NULL)

    {

        t2 = t;

        return (largest(t->right));
    }

    else

        return (t->data);
}