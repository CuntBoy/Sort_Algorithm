#include <iostream>
#include "Octree.hpp"
#include <vector>

namespace Octree
{
    static void outputInfo()
    {
        std::cout << "create of OctTree" << std::endl;
    }

}


namespace OcttreeData
{
    class OctData
    {
    public:
        OctData()
        {
            m_data.clear();
        }
        
        std::vector<double>& data()
        {
            return m_data;
        }

    private:
        std::vector<double> m_data;

    };

}





int main()
{
    using Octree::outputInfo;
    outputInfo();

    Octree::OctNode<OcttreeData::OctData> root;
    Octree::createOctree(&root, 10, Octree::Box());


    return 0;
}