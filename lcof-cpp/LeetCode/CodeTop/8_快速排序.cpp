class Solution
{
public:
    // 快排：随机选择一个k，交换左右两边的数字，使左边都小于，右边都大于
    vector<int> sortArray(vector<int> &nums)
    {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quicksort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;
        // partition将nums分为两部分，左边都小于pivot，右边都大于pivot
        int p = partition(nums, l, r);
        quicksort(nums, l, p - 1);
        quicksort(nums, p + 1, r);
    }

    int partition(vector<int> &nums, int l, int r)
    {
        // 随机选择一个index，交换l和index所指的元素
        int rand_idx = rand() % (r - l + 1) + l;
        swap(nums[rand_idx], nums[l]);
        // 双指针
        int i = l + 1, j = r;
        // 注意这里是小于等于，当相等时也要和pivot比较
        while (i <= j) // 简单数组 [5, 2] 此时 i == jd但是2并没有划分到左边 所以需要"等于"号
        {
            // 碰到相等元素时停止，这样有助于将元素均匀分散到pivote两边
            // 避免退化到O(n*n)
            // 从左边找第一个大于pivot的元素
            while (i <= j && nums[i] < nums[l])
                i++;
            // 从右边找第一个小于pivot的元素
            while (i <= j && nums[l] < nums[j])
                j--;
            // 此时i和j符合条件，交换它们
            if (i <= j)
                swap(nums[i++], nums[j--]);
        }
        // 此时j指向的是最后一个小于pivot的元素
        // 2 4 1 3
        // 2 1 4 3 ==> 此时 1=>j 4=>i 此时要和j交换
        swap(nums[l], nums[j]);
        return j;
    }
};