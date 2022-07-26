#include <iostream>
#include <cassert>
#include <memory>

namespace Octree
{
    // 场景的包围盒 
    struct boundingBox
    {
        boundingBox(){}
        double xmin{0}, xmax{0};
        double ymin{0}, ymax{0};
        double zmin{0}, zmax{0};
    };

    using Box = boundingBox;

    template<typename T>
    struct Node
    {
        T m_data;
        Box m_box;

        T& getData()
        {
            return m_data;
        }

        Box& getBoundingBox()
        {
            return m_box;
        }

    };

    template<typename T>
    struct OctNode :public Node<T>
    {
        // sub Node 
        OctNode* m_top_left_front{nullptr};
        OctNode* m_top_left_back{nullptr};

        OctNode* m_top_right_front{ nullptr };
        OctNode* m_top_right_back{ nullptr };

        OctNode* m_bottom_left_front{ nullptr };
        OctNode* m_bottom_left_back{ nullptr };

        OctNode* m_bottom_right_front{ nullptr };
        OctNode* m_bottom_right_back{ nullptr };
    };


    template<typename T>
    void createOctree(OctNode<T>* root, int maxdepth, Box& boundingBox)
    {
        using std::cout;
        using std::endl;

        // 创建八叉树
        assert(root);


        cout << "create Octree Success" << endl;

    }




}




