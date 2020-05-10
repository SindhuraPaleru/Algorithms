# include<stdio.h>
struct item
{
int index;
float weight, profit, ratio;
float solution;
};
typedef struct item Item;
void knapsack(Item a[], int n, float capacity) {
Item temp;
float u,tp = 0;
int i, j;
for (i = 0; i < n; i++)
for (j = i + 1; j < n; j++)
if (a[i].ratio < a[j].ratio) {
temp = a[j];
a[j] = a[i];
a[i] = temp;
}
u = capacity;
for (i = 0; i < n; i++)
a[i].solution = 0.0;
for (i = 0; i < n; i++) {
if (a[i].weight > u)
break;
else {
a[i].solution = 1.0;
tp = tp + a[i].profit;
u = u - a[i].weight;
}
}
if (i < n)
a[i].solution = u / a[i].weight;
tp = tp + (a[i].solution * a[i].profit);
2
for (i = 0; i < n; i++)
for (j = i + 1; j < n; j++)
if (a[i].index > a[j].index) {
temp = a[j];
a[j] = a[i];
a[i] = temp;
}
printf("\nThe result vector is:- ");
for (i = 0; i < n; i++)
printf("\t%f\t", a[i].solution);
printf("\nMaximum profit is:- %f", tp);
}
int main() {
Item a[20];
float capacity;
int num, i, j;
printf("\nEnter the no. of objects:- ");
scanf("%d", &num);
printf("\nEnter the wts and profits of each object:- ");
for (i = 0; i < num; i++) {
printf("\n object%d :",i+1);
a[i].index=i;
scanf("%f %f", &a[i].weight, &a[i].profit);
a[i].ratio=a[i].profit/a[i].weight;
}
printf("\nEnter the capacityacity of knapsack:- ");
scanf("%f", &capacity);
knapsack(a,num,capacity);
return(0);
}  
