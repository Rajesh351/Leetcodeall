class Solution {
public:
bool isSubfolder(const std::string& folder1, const std::string& folder2) {
    // folder2 should start with folder1 followed by a '/'
    return folder2.find(folder1) == 0 && folder2[folder1.size()] == '/';
}
    vector<string> removeSubfolders(vector<string>& folder) {
        
        sort(folder.begin(),folder.end());
            
    std::vector<std::string> result;
    
    // Step 2: Iterate through the sorted folders
    for (const auto& folder : folder) {
        // Step 3: Add to result if it's not a subfolder of the last added folder
        if (result.empty() || !isSubfolder(result.back(), folder)) {
            result.push_back(folder);
        }
    }
    
    return result;
    }
};