
class NestedIterator {
private:
    vector<int> flattened;
    int i;
    int n;
    vector<int> flatten(const std::vector<NestedInteger>& nested) {
        vector<int> result;
        for (auto ni : nested) {
            if (ni.isInteger()) {
                result.push_back(ni.getInteger());
            } else {
                auto subList = flatten(ni.getList());
                result.insert(result.end(), subList.begin(), subList.end());
            }
        }
        return result;
    }

public:
    NestedIterator(std::vector<NestedInteger> nestedList) {
        flattened = flatten(nestedList);
        i = 0;
        n=flattened.size();
    }

    int next() {
        return flattened[i++];
    }

    bool hasNext() {
        return i<n;
    }
};