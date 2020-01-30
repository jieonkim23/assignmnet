#include <stdio.h>
#include <stdlib.h>


#define ATTEMPT_LIMIT 9

/**
* @brief : generate and return a random digit in 0~9
* @return : a digit in 0~9
* @param : none
*/
int generate_a_digit() {
	return (rand()%10);
}

/**
* @brief : check digit duplication
* @return : return true if all digits of the number are different, false otherwise.
* @param : num - a 3-digits number to be checked for digit duplication.
*/
int is_different_digits(int num) {
	int digits[3];
	int is_different = 1;
	
	digits[0] = num%10;
	digits[1] = (num/10)%10;
	digits[2] = (num/100)%10;
	if ((digits[0] == digits[1]) ||(digits[0] == digits[2]) ||(digits[1] == digits[2]) )
		is_different = 0;
	
	return is_different;
}

int generate_target_number() {
	int num1, num2, num3, num;
	
	num1 = rand()%10;  //generate_a_digit()
	
	do{
		num2 = rand()%10;  //generate_a_digit()
	} while (num1==num2);
	
	num = num1*10 + num2;
	
	do{
		num3 = rand()%10;  //generate_a_digit()
	} while(num3==num1 || num3==num2);
	
	num = num*10 +num3;
	
	return num;
}

int guess_number()
{
	int num;
	while (1) {
		printf("Enter your guess : ");
		scanf("%d",&num);
	if (num < 1000 && is_different_digits(num)) break;
		printf("Input Error !!! ? Wrong number format\n");
	}
	return num;
}

void receive_match_result(int result, int guessed)
{
	int n_strike = result/10, n_ball = result%10;
	switch (result) {
		case 30 : printf("Congratulation !!!\n");
				break;
		case 0 : printf("Oops !!!\n");
				break;
		default : printf("Nice try !!!\n");
	}
	printf("Your guess %d is [%d] strikes and [%d] balls\n", guessed, n_strike, n_ball);
}

/**
* @brief : compare the guessed number with the target and return the match results
* @return : return 2-digits number, 1st digit stands for the number of strikes and 2nd digit stands for the number of balls. For example 11 means 1 strike 1 ball
* @param : target - 3-digits target integer
guessed - 3-digits guessed integer
*/
int get_match_result(int target, int guessed)
{
	int n_strike=0, n_ball=0;
	int t_digits[3];
	t_digits[0] = target%10;
	t_digits[1] = (target/10)%10;
	t_digits[2] = (target/100)%10;
	
	int g_digits[3];
	g_digits[0] = guessed%10;
	g_digits[1] = (guessed/10)%10;
	g_digits[2] = (guessed/100)%10;
	
	int i, j;
	
	for(i=0;i<3;i++)	{
		for(j=0;j<3;j++){
			if(t_digits[i]==g_digits[j]){
					if(i==j)	n_strike += 1;
					else		n_ball += 1;
			}
		}
	}

	return (n_strike*10 + n_ball);
}

int main(void)
{
	int n_attempt = 0;
	int target_num, guessed_num, match_result;
	
	srand(time(0));
	target_num = generate_target_number();
	do {
		printf("Attempt [%d/%d] ",++n_attempt, ATTEMPT_LIMIT);
		guessed_num = guess_number();
		match_result = get_match_result(target_num, guessed_num);
		receive_match_result(match_result, guessed_num);
	} while (n_attempt <= ATTEMPT_LIMIT && match_result != 30);
	
	if (match_result == 30)
		printf("Congratulation!!! You Win\n");
	else
		printf("Nice Try!!! But You Lose, The target number is %d\n", target_num);
	return 0;
}
