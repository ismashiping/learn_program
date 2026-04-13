#include <memory>
class ResourceManager{
    private:
        std::unique_ptr<int> m_resource;
        public:
        ResourceManager(int *resource);
        int getValue() const;
        void setValue(int newValue);
        ResourceManager(const ResourceManager& other) =delete;
        ResourceManager& operator=(const ResourceManager& other) =delete;
        
};
void testUniquePtr();