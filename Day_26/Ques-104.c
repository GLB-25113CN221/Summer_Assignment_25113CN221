#include <stdio.h>

int main()
{

    // Q-104 Write a program to create quiz application

    char answer; // answer = to input the answer of the participant
    int score = 0;

    printf("=== QUIZ APPLICATION ===\n\n");

    printf("There are 10 philosophy based questions in this quiz.\n");

    printf("\nEach correct answer awards +4 and each wrong answer gets -1.\n");

    printf("\nTo skip a question enter 'E'\n");

    printf("\nPress Enter to continue...");
    getchar();
    getchar();

    printf("\n\nQuestion-1: Who is known as the 'Father of Western Philosophy'?\n\n");

    printf("A. Aristotle\nB. Plato\nC. Socrates\nD. Pythagoras\n\n");

    printf("Your answer: ");
    scanf("%c", &answer);

    if (answer == 'C' || answer == 'c')
    {

        score += 4;
        printf("\nCorrect Answer!\n");
    }
    else if (answer == 'E' || answer == 'e')
    {
        printf("\nThe correct answer is: C\n");
    }
    else
    {
        score -= 1;
        printf("\nOops! Incorrect answer. The correct answer is C.\n");
    }

    printf("Press Enter to continue...");
    getchar();
    getchar();

    printf("\n\nQuestion-2: 'I think, therefore I am'- who said this?\n\n");

    printf("A. Plato\nB. Rene Descartes\nC. Immanuel Kant\nD. Friedrich Nietzche\n\n");

    printf("Your answer: ");
    scanf("%c", &answer);

    if (answer == 'B' || answer == 'b')
    {

        score += 4;
        printf("\nCorrect Answer!\n");
    }
    else if (answer == 'E' || answer == 'e')
    {
        printf("\nThe correct answer is: B\n");
    }
    else
    {
        score -= 1;
        printf("\nOops! Incorrect answer. The correct answer is B.\n");
    }

    printf("Press Enter to continue...");
    getchar();
    getchar();

    printf("\n\nQuestion-3: Which philosopher wrote 'The Republic'\n\n");

    printf("A. Aristotle\nB. Plato\nC. Socrates\nD. Thomas Hobbes\n\n");

    printf("Your answer: ");
    scanf("%c", &answer);

    if (answer == 'B' || answer == 'b')
    {

        score += 4;
        printf("\nCorrect Answer!\n");
    }
    else if (answer == 'E' || answer == 'e')
    {
        printf("\nThe correct answer is: B\n");
    }
    else
    {
        score -= 1;
        printf("\nOops! Incorrect answer. The correct answer is B.\n");
    }

    printf("Press Enter to continue...");
    getchar();
    getchar();

    printf("\n\nQuestion-4: What is the philosophical study of knowledge called?\n\n");

    printf("A. Epistemology\nB. Metaphysics\nC. Ethics\nD. Aesthetics\n\n");

    printf("Your answer: ");
    scanf("%c", &answer);

    if (answer == 'A' || answer == 'a')
    {

        score += 4;
        printf("\nCorrect Answer!\n");
    }
    else if (answer == 'E' || answer == 'e')
    {
        printf("\nThe correct answer is: A\n");
    }
    else
    {
        score -= 1;
        printf("\nOops! Incorrect answer. The correct answer is A.\n");
    }

    printf("Press Enter to continue...");
    getchar();
    getchar();

    printf("\n\nQuestion-5: Which philosopher wrote'The Prince'?\n\n");

    printf("A. Thomas Hobbes\nB. John Locke\nC. Immanuel Kant\nD. Niccolo Machiavelli\n\n");

    printf("Your answer: ");
    scanf("%c", &answer);

    if (answer == 'D' || answer == 'd')
    {

        score += 4;
        printf("\nCorrect Answer!\n");
    }
    else if (answer == 'E' || answer == 'e')
    {
        printf("\nThe correct answer is: D\n");
    }
    else
    {
        score -= 1;
        printf("\nOops! Incorrect answer. The correct answer is D.\n");
    }

    printf("Press Enter to continue...");
    getchar();
    getchar();

    printf("\n\nQuestion-6: What is the belief that life has no intrinsic meaning called?\n\n");

    printf("A. Stoicism\nB. Existentialism\nC. Nihilism\nD. Hedonism\n\n");

    printf("Your answer: ");
    scanf("%c", &answer);

    if (answer == 'C' || answer == 'c')
    {

        score += 4;
        printf("\nCorrect Answer!\n");
    }
    else if (answer == 'E' || answer == 'e')
    {
        printf("\nThe correct answer is: C\n");
    }
    else
    {
        score -= 1;
        printf("\nOops! Incorrect answer. The correct answer is C.\n");
    }

    printf("Press Enter to continue...");
    getchar();
    getchar();

    printf("\n\nQuestion-7: Which philosopher is known for 'Social Contract' theory?\n\n");

    printf("A. Voltaire\nB. Thomas Hobbes\nC. John Locke\nD. Jean-Jacques Rousseau\n\n");

    printf("Your answer: ");
    scanf("%c", &answer);

    if (answer == 'D' || answer == 'd')
    {

        score += 4;
        printf("\nCorrect Answer!\n");
    }
    else if (answer == 'E' || answer == 'e')
    {
        printf("\nThe correct answer is: D\n");
    }
    else
    {
        score -= 1;
        printf("\nOops! Incorrect answer. The correct answer is D.\n");
    }

    printf("Press Enter to continue...");
    getchar();
    getchar();

    printf("\n\nQuestion-8: Which philosophy emphasizes duty and moral rules?\n\n");

    printf("A. Deontology\nB. Consequentialism\nC. Nihilism\nD. Hedonism\n\n");

    printf("Your answer: ");
    scanf("%c", &answer);

    if (answer == 'A' || answer == 'a')
    {

        score += 4;
        printf("\nCorrect Answer!\n");
    }
    else if (answer == 'E' || answer == 'e')
    {
        printf("\nThe correct answer is: A\n");
    }
    else
    {
        score -= 1;
        printf("\nOops! Incorrect answer. The correct answer is A.\n");
    }

    printf("Press Enter to continue...");
    getchar();
    getchar();

    printf("\n\nQuestion-9: Who is the founder of Stoicism?\n\n");

    printf("A. Seneca\nB. Zeno of Citium\nC. Epictetus\nD. Marcus Aurelius\n\n");

    printf("Your answer: ");
    scanf("%c", &answer);

    if (answer == 'B' || answer == 'b')
    {

        score += 4;
        printf("\nCorrect Answer!\n");
    }
    else if (answer == 'E' || answer == 'e')
    {
        printf("\nThe correct answer is: B\n");
    }
    else
    {
        score -= 1;
        printf("\nOops! Incorrect answer. The correct answer is B.\n");
    }

    printf("Press Enter to continue...");
    getchar();
    getchar();

    printf("\n\nQuestion-10: What is the study of nature of reality called?\n\n");

    printf("A. Metaphysics\nB. Epistemology\nC. Ethics\nD. Aesthetics\n\n");

    printf("Your answer: ");
    scanf("%c", &answer);

    if (answer == 'A' || answer == 'a')
    {

        score += 4;
        printf("\nCorrect Answer!\n");
    }
    else if (answer == 'E' || answer == 'e')
    {
        printf("\nThe correct answer is: A\n");
    }
    else
    {
        score -= 1;
        printf("\nOops! Incorrect answer. The correct answer is A.\n");
    }

    printf("Press Enter to continue...");
    getchar();
    getchar();

    printf("\n____ QUIZ COMPLETED _____\n\n");
    printf("Your Score: %d/40\n", score);
    printf("Percentage: %d%%\n\n", (score * 100) / 40);

    return 0;
}