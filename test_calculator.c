#include "unity.h"
#include "calculator.h"

void setUp(void){

}

void tearDown(void){

}

// add()

void test_add_positive_numbers(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3)); // TEST_ASSERT_EQUAL(expected, actual)
}

void test_add_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(1, add(5, -4)); //expect 5 + -4 = 1
}
void test_add_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-7, add(-3, -4)); //expect -3 + -4 = -7
    
}
    
    //NOTE: We can do multiple validations in one test
void test_add_zero(void) {
    TEST_ASSERT_EQUAL(10, add(10, 0)); //expect 10 + 0 = 10
    TEST_ASSERT_EQUAL(0, add(0, 0)); //expect 0 + 0 = 0
}

void test_add_overflow(void) {
    int result = add(INT_MAX, 1); //Should wrap around or cause undefined behavior
    TEST_ASSERT_TRUE(result < 0); //This checks if overflow occurred
}

// Test integer underflow
void test_add_underflow(void) {
int result = add(INT_MIN, -1);
TEST_ASSERT_TRUE(result > 0); //This checks if underflow occurred
}

// subtract()

void test_sub_positive_numbers(void) {
    TEST_ASSERT_EQUAL(-1, subtract(2, 3)); // TEST_ASSERT_EQUAL(expected, actual)
}

void test_sub_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(9, subtract(5, -4)); //expect 5 - -4 = 9
}
void test_sub_negative_numbers(void) {
    TEST_ASSERT_EQUAL(1, subtract(-3, -4)); //expect -3 - -4 = -1
    
}

// multiply

void test_multiply_positive_numbers(void) {
    TEST_ASSERT_EQUAL(6, multiply(2, 3)); // TEST_ASSERT_EQUAL(expected, actual)
}

void test_multiply_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-20, multiply(5, -4)); //expect 5 * -4 = -20
}
void test_multiply_negative_numbers(void) {
    TEST_ASSERT_EQUAL(12, multiply(-3, -4)); //expect -3 * -4 = 12
    
}

// divide

void test_divide_positive_numbers(void) {
    TEST_ASSERT_EQUAL(0, divide(2, 3)); // TEST_ASSERT_EQUAL(expected, actual)
}

void test_divide_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-12, divide(50, -4)); //expect 50 * -4 = -12
}
void test_divide_negative_numbers(void) {
    TEST_ASSERT_EQUAL(7, divide(-30, -4)); //expect -30 / -4 = 7
    
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_positive_numbers);
    RUN_TEST(test_add_positive_and_negative_numbers);
    RUN_TEST(test_add_negative_numbers);
    RUN_TEST(test_add_zero);
    RUN_TEST(test_add_overflow);
    RUN_TEST(test_add_underflow);

    RUN_TEST(test_sub_positive_numbers);
    RUN_TEST(test_sub_positive_and_negative_numbers);
    RUN_TEST(test_sub_negative_numbers);

    RUN_TEST(test_multiply_positive_numbers);
    RUN_TEST(test_multiply_positive_and_negative_numbers);
    RUN_TEST(test_multiply_negative_numbers);

    RUN_TEST(test_divide_positive_numbers);
    RUN_TEST(test_divide_positive_and_negative_numbers);
    RUN_TEST(test_divide_negative_numbers);
    return UNITY_END();
}