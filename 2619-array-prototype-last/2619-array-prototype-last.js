/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    // 'this' refers to the array the method is being called on.
    
    // Step 1: Handle the edge case of an empty array
    if (this.length === 0) {
        return -1;
    }
    
    // Step 2: Access the last element in O(1) time
    // Since arrays are 0-indexed, the last element is at length - 1
    return this[this.length - 1];
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */