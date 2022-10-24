//
// Created by 17336 on 2022/3/9.
//

#ifndef HOT100_QUICKSORT_H
#define HOT100_QUICKSORT_H

#include <vector>

using namespace std;


class sorts {
public:
    static void quickSort(vector<int> &nums, int l, int r) {
        if (l < r) {
            int mid = sorts::partition(nums, l, r);
            quickSort(nums, l, mid - 1);
            quickSort(nums, mid + 1, r);
        }
    }

    //快速选择算法
    int findK(vector<int> &nums, int k) {
        int res = -1, l = 0, r = nums.size() - 1;
        while (res != k) {
            res = partition(nums, l, r);
            if (res > k) r = res - 1;
            if (res < k) l = res + 1;
        }
        return nums[res];
    }

    static int partition(vector<int> &nums, int l, int r) {
        //随机选取一个元素作为枢轴
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[r]);
        int pilot = nums[l];

        while (l < r) {
            while (l < r && nums[r] >= pilot) --r;
            nums[l] = nums[r];
            while (l < r && nums[l] <= pilot) ++l;
            nums[r] = nums[l];
        }
        nums[l] = pilot;
        return l;
    }

    //归并排序
    static void mergeSort(vector<int> &nums, int l, int r) {
        if (l < r) {
            //将nums一分为二，分别排序两部分然后合并
            int mid = (l + r) / 2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid + 1, r);
            mergeT(nums, l, mid, mid + 1, r);
        }
    }

    //合并
    static void mergeT(vector<int> &nums, int l1, int r1, int l2, int r2) {
        //先复制一份副本
        vector<int> fir(nums.begin() + l1, nums.begin() + r1 + 1);
        vector<int> sec(nums.begin() + l2, nums.begin() + r2 + 1);
        auto p = fir.begin(), q = sec.begin();
        int i = l1;
        //归并
        while (p != fir.end() && q != sec.end()) {
            if (*p < *q) nums[i++] = *(p++);
            else nums[i++] = *(q++);
        }
        //直接复制没归并完的
        while (p != fir.end()) {
            nums[i++] = *(p++);
        }
        while (q != sec.end()) {
            nums[i++] = *(q++);
        }
    }

    //堆排序
    static void heapSort0(vector<int> &nums) {
        initHeap0(nums);
        int i = nums.size();
        //一个一个把堆顶元素交换到队尾，同时向前移动队尾指针
        while (i > 0) {
            //堆顶一定是最大的，直接交换到表尾
            swap(nums[0], nums[i - 1]);
            --i;
            //向下调整
            int j = 1;
            while (2 * j <= i) {
                //取孩子中较大的一个
                int l = 2 * j, r = l + 1, m;
                if (r > i) m = l;
                else m = nums[l - 1] > nums[r - 1] ? l : r;
                //如果已经比孩子大，不用向下调整了
                if (nums[j - 1] >= nums[m - 1]) break;
                swap(nums[j - 1], nums[m - 1]);
                j = m;
            }
        }
    }

    //初始化堆
    static void initHeap0(vector<int> &nums) {
        if (nums.size() < 2) return;
        int len = nums.size(), i = len / 2;
        //从最后一个非叶节点一直向上调整到第一个非叶节点即根节点
        while (i > 0) {
            //找出i左右孩子中较大的一个
            int l = 2 * i, r = l + 1, m;
            if (r > len) m = l;
            else m = nums[l - 1] > nums[r - 1] ? l : r;
            //如果根比孩子小，则交换
            if (nums[i - 1] < nums[m - 1]) {
                swap(nums[i - 1], nums[m - 1]);
                //如果交换之后需要向下调整
                int j = m;
                while (2 * j <= len) {
                    //取孩子中较大的一个
                    int l = 2 * j, r = l + 1, m;
                    if (r > len) m = l;
                    else m = nums[l - 1] > nums[r - 1] ? l : r;
                    //如果根已经比孩子大，则不需要调整了
                    if (nums[j - 1] >= nums[m - 1]) break;
                    swap(nums[j - 1], nums[m - 1]);
                    j = m;
                }
            }
            --i;
        }
    }

    //可以看到堆排序和堆初始化有很多重复的操作：向下调整堆，重构了一下
    static void heapSort(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) return;
        //从最后一个非叶节点向上开始，每个非叶节点都向下调整
        for (int i = len / 2 - 1; i >= 0; --i) {
            heapAdjust(nums, i, len - 1);
        }
        //堆顶依次出堆，并调整堆
        for (int i = len - 1; i > 0; --i) {
            swap(nums[i], nums[0]);
            heapAdjust(nums, 0, i - 1);
        }
    }

    //从i开始向下调整堆：end为堆中最后一个元素下标,i为要调整的下标
    static void heapAdjust(vector<int> &nums, int i, int end) {
        //如果i左孩子超出end界限
        if (2 * i + 1 > end) return;
        //取i较大的孩子
        int l = 2 * i + 1, r = l + 1, m;
        if (r > end) m = l;
        else m = nums[l] > nums[r] ? l : r;
        if (nums[i] >= nums[m]) return;
        swap(nums[i], nums[m]);
        heapAdjust(nums, m, end);
    }

    //计数排序：算导版本，稳定
    void countSort(vector<int> &nums){
        int len=nums.size();
        vector<int> count(len,0),res(len);
        for (const auto &num: nums) {
            ++count[num];
        }
        for (int i = 1; i < len; ++i) {
            count[i]+=count[i-1];
        }
        for (int i = len-1; i >=0 ; --i) {
            res[count[nums[i]]]=nums[i];
            --count[nums[i]];
        }
    }
};

#endif //HOT100_QUICKSORT_H
