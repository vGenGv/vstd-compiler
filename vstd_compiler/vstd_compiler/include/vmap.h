#pragma once

#include <vector>
#include <list>

namespace vstd
{
	//前向声明顶点类
	template<typename VertexDType, typename EdgeDType>
	class VMapVertex;

	//边类
	template<typename VertexDType, typename EdgeDType>
	class VMapEdge
	{
	public:
		typedef VMapVertex<VertexDType, EdgeDType> Vertex;
		typedef VMapEdge<VertexDType, EdgeDType> Edge;
		typedef std::vector<Vertex*> VertexVector;

		VMapEdge() = default;
		VMapEdge(const EdgeDType data): m_data(data) {}
		VMapEdge(const VertexVector targets) :m_targets(targets) {}
		VMapEdge(const EdgeDType data, const VertexVector targets)
			:m_data(data), m_targets(targets) {}
		~VMapEdge() = default;

		//复制
		VMapEdge(const Edge &edge)
			:m_data(edge.m_data), m_from(edge.m_from), m_targets(edge.m_targets) {}
		//赋值
		Edge &operator=(const Edge &edge) {
			m_data = edge.data();
			m_from = edge.from();
			m_targets = edge.targets();
			return *this;
		}

		//等于
		bool operator==(const Edge &edge)const {
			return m_data == edge.data() && m_from == edge.from() && m_targets == edge.targets();
		}
		//不等于
		bool operator!=(const Edge &edge)const { return !operator==(edge); }

		//读数据
		const EdgeDType &data()const { return m_data; }
		//获取数据
		EdgeDType getData()const { return m_data; }
		//写数据
		void setData(const EdgeDType data) { m_data = data; }

		//读来源
		Vertex *const &from()const { return m_from; }
		//获取来源
		Vertex *getFrom()const { return m_from; }
		//写来源
		void setFrom(Vertex *vertex) { m_from = vertex; }

		//读目标
		const VertexVector &targets()const { return m_targets; }
		//获取目标
		VertexVector getTargets()const { return m_targets; }
		//写目标
		void setTargets(const VertexVector targets) { m_targets = targets; }
		//清空目标
		void clearTargets() { m_targets.clear(); }
		//存在目标
		bool hasTarget(const Vertex *const vertex)const {
			return std::find(m_targets.begin(), m_targets.end(), vertex) != m_targets.end();
		}
		//添加目标
		void addTarget(Vertex *const vertex) {
			if (hasTarget(vertex))
				m_targets.push_back(vertex);
		}
		//删除目标
		void removeTarget(Vertex *const vertex) {
			auto it = std::find(m_targets.begin(), m_targets.end(), vertex);
			if (it != m_targets.end())
				m_targets.erase(it);
		}

	private:
		EdgeDType m_data; //数据
		Vertex *m_from; //来源
		VertexVector m_targets; //目标
	};

	template<typename VertexDType, typename EdgeDType>
	class VMapVertex
	{
	public:
		typedef VMapVertex<VertexDType, EdgeDType> Vertex;
		typedef VMapEdge<VertexDType, EdgeDType> Edge;
		typedef std::list<Edge*> EdgeList;

	private:
		VertexDType m_data;
	};

	template<typename VertexDType = int, typename EdgeDType = int>
	class VMap
	{
	public:
		typedef VMapVertex<VertexDType, EdgeDType> Vertex;
		typedef VMapEdge<VertexDType, EdgeDType> Edge;
	};
}