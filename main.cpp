#include "pch.h"

struct Vertex
{
    float x = 0.0f;
    Vertex(float x)
        : x(x)
    {
    }
    void Show() const
    {
        printf("%f ", x);
    }
};

struct Mesh
{
    unsigned int mOffset = 0;
    unsigned int mSize = 0;

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    void show() const{

        for (unsigned i = 0; i < mSize;i++)
        {
            auto &ind = indices[mOffset + i];
            auto &vtx = vertices[ind];

            vtx.Show();
        }
        printf("\n");
    }
};

struct Model
{
    std::vector<Mesh> meshes;
    const std::vector<Mesh> MultiMesh() const {
        std::vector<Mesh> res;
        Mesh sub_mesh = SubMesh();

        uint64_t sub_off = 0;
        for (const auto &mesh : meshes)
        {
            Mesh rMesh = sub_mesh;
            rMesh.mSize = mesh.mSize;
            rMesh.mOffset = sub_off;
            sub_off += mesh.mSize;

            res.push_back(rMesh);
        }
        return res;
    };
    const Mesh SubMesh() const
    {
        Mesh res;
        auto &vertices = res.vertices;
        auto &indices = res.indices;
        auto &off = res.mOffset;
        auto &sz = res.mSize;

        uint64_t vtx_off = 0;
        

        for (const auto &mesh : meshes)
        {

            const auto &meshV = mesh.vertices;
            auto meshI = mesh.indices;

            vertices.insert(vertices.end(), meshV.begin(), meshV.end());

            for (auto &mi : meshI)
            {
                // mi += indSize;
                mi += vtx_off;
            }
            vtx_off += meshV.size();

            indices.insert(indices.end(), meshI.begin(), meshI.end());

            sz += meshI.size();
        }

        return res;
    }
};


int main(){

    Mesh m1 =
        {
            0, 3, {0.6f, 1.0f, 1.0f, 0.5f, 0.6f}, {0, 1, 4}};
    Mesh m2 =
        {
            0, 3, {0.1f, 0.5f, 0.6f, 0.7f, 1.5f}, {1, 1, 3}};
    Mesh m3 =
        {0, 4, {0.5f, 7.0f, 0.f}, {0, 0, 1, 2}};

    m1.show();
    m2.show();
    m3.show();

    Model model;
    model.meshes.push_back(m1);
    model.meshes.push_back(m2);
    model.meshes.push_back(m3);

    Mesh mr = model.SubMesh();

    mr.show();

    std::vector<Mesh> ms2 = model.MultiMesh();

    for (auto &mm : ms2)
    {
        mm.show();
    }
};
