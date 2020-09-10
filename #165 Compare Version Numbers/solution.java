class Solution {
    public int compareVersion(String version1, String version2) {
        String[] version1Array = version1.split("\\.");
        String[] version2Array = version2.split("\\.");
        
        int remaining1Size = version1Array.length;
        int remaining2Size = version2Array.length;
        
        for(int i = 0; i < version1Array.length && i < version2Array.length; i++)
        {
            if(Integer.parseInt(version1Array[i]) > Integer.parseInt(version2Array[i]))
                return 1;
            else if(Integer.parseInt(version1Array[i]) < Integer.parseInt(version2Array[i]))
                return -1;
            remaining1Size--;
            remaining2Size--;
        }
        while(remaining1Size > 0 || remaining2Size > 0)
        {
            if(remaining1Size > 0)
            {
                if(Integer.parseInt(version1Array[version1Array.length-remaining1Size]) != 0)
                    return 1;
                remaining1Size--;
            }
            else if(remaining2Size > 0)
            {
                if(Integer.parseInt(version2Array[version2Array.length-remaining2Size]) != 0)
                    return -1;
                remaining2Size--;
            }
        }
        return 0;
    }
}