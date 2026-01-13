/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
        let maxNum = 0;
        let minNum = 0;
        let n = nums.length;
        for(let num of nums){
            if(num > maxNum){
                minNum = maxNum;
                maxNum = num;
            }
            else if(num > minNum){
                minNum = num;
            }
        }
        minNum = minNum - 1;
        maxNum = maxNum - 1;
        return minNum * maxNum;
};
