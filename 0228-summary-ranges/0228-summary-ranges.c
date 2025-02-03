/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if(numsSize == 0)
    {
        *returnSize = 0;
        return NULL; 
    }

    int start = 0;
    int count = 0;

    char** result = (char**) malloc(numsSize * sizeof(char*));

    for(int i=1; i<=numsSize; i++)
    {
        if(i == numsSize || nums[i] != nums[i-1]+1)
        {
            result[count] = (char*) malloc(25*sizeof(char));

            if(start == i-1){
                sprintf(result[count],"%d",nums[start]);
            }
            else{
                sprintf(result[count],"%d->%d",nums[start],nums[i-1]);
            }

            start = i;
            count++;
        }
    }

    *returnSize = count;
    return result;
}