#ifndef KNAPSACK_H_
#define KNAPSACK_H_
#define MAX 100

extern int V[MAX + 1];
extern int W[MAX + 1];
extern int dp[MAX + 1][MAX + 1];
extern int C;
extern int J;

void initData(void);
void createData(void);
void printData(void);
int calc(void);

#endif /* KNAPSACK_H_ */
