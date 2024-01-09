#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
  int attribute; //attribute index for decision node
  double threshold; //threshold value for decision nodes
  int classification; // class label for leaf nodes
  struct Node* left;
  struct Node* right;
};
typedef struct Node Node;

Node* createNode(int attribute, double threshold, int classification){
  Node *newNode = (Node*)malloc(sizeof(Node));
  if(newNode == NULL){
    printf("Memory alocation error\n");
    exit(EXIT_FAILURE);
  }
  newNode->attribute=attribute;
  newNode->classification=classification;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void insertNode(Node **root, int attribute, double threshold, int classification) {
    if (*root == NULL) {
        *root = createNode(attribute, threshold, classification);
    } else {
        if (attribute < (*root)->attribute) {
            insertNode(&(*root)->left, attribute, threshold, classification);
        } else {
            insertNode(&(*root)->right, attribute, threshold, classification);
        }
    }
}

void readTrainingData(const char *filename, double ***trainingData, int **trueLabels, int *numAttributes, int *numSamples){
  FILE *file = fopen(filename, "r");
  if(file == NULL){
    printf("Error opening file\n");
    exit(EXIT_FAILURE);
  }
  fscanf(file, "%d %d %d", numAttributes, &(*numSamples), &(*numAttributes));

  *trainingData = (double **)malloc(sizeof(double *) * (*numSamples));
  *trueLabels = (int *)malloc(sizeof(int) * (*numSamples));

  for (int i = 0; i < *numSamples; i++) {
        (*trainingData)[i] = (double *)malloc(sizeof(double) * (*numAttributes));
        for (int j = 0; j < *numAttributes; j++) {
            fscanf(file, "%lf,", &(*trainingData)[i][j]);
        }
        fscanf(file, "%d", &(*trueLabels)[i]);
    }

    fclose(file);
}

void constructTree(Node **root, double **trainingData, int numAttributes, int numSamples) {
    // Your construction logic goes here (e.g., recursively split based on numeric criteria)
    // For simplicity, let's assume a binary tree with a fixed depth for this example.
    // You'll need to implement a more sophisticated algorithm for a real-world scenario.

    // Placeholder code (replace with your own logic)
    for (int i = 0; i < numSamples; i++) {
        insertNode(root, 0, trainingData[i][0], trainingData[i][numAttributes - 1]);
    }
}

// Function to free memory used by the tree
void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
// Function to free memory used by training data
void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}




int main(){
  // Read training data from treino.txt
    double **trainingData;
    int *trueLabels;
    int numAttributes, numSamples;

    readTrainingData("treino.txt", &trainingData, &trueLabels, &numAttributes, &numSamples);

    // Construct the decision tree
    Node *root = NULL;
    constructTree(&root, trainingData, numAttributes, numSamples);

    // Clean up (free allocated memory)
    freeTree(root);
    freeTrainingData(&trainingData, &trueLabels, numSamples);

    return 0;
}
