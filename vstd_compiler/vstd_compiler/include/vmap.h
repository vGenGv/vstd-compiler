#pragma once

#include <vector>
#include <list>

namespace vstd
{
	//ǰ������������
	template<typename VertexDType, typename EdgeDType>
	class VMapVertex;

	//����
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

		//����
		VMapEdge(const Edge &edge)
			:m_data(edge.m_data), m_from(edge.m_from), m_targets(edge.m_targets) {}
		//��ֵ
		Edge &operator=(const Edge &edge) {
			m_data = edge.data();
			m_from = edge.from();
			m_targets = edge.targets();
			return *this;
		}

		//����
		bool operator==(const Edge &edge)const {
			return m_data == edge.data() && m_from == edge.from() && m_targets == edge.targets();
		}
		//������
		bool operator!=(const Edge &edge)const { return !operator==(edge); }

		//������
		const EdgeDType &data()const { return m_data; }
		//��ȡ����
		EdgeDType getData()const { return m_data; }
		//д����
		void setData(const EdgeDType data) { m_data = data; }

		//����Դ
		Vertex *const &from()const { return m_from; }
		//��ȡ��Դ
		Vertex *getFrom()const { return m_from; }
		//д��Դ
		void setFrom(Vertex *vertex) { m_from = vertex; }

		//��Ŀ��
		const VertexVector &targets()const { return m_targets; }
		//��ȡĿ��
		VertexVector getTargets()const { return m_targets; }
		//дĿ��
		void setTargets(const VertexVector targets) { m_targets = targets; }
		//���Ŀ��
		void clearTargets() { m_targets.clear(); }
		//����Ŀ��
		bool hasTarget(const Vertex *const vertex)const {
			return std::find(m_targets.begin(), m_targets.end(), vertex) != m_targets.end();
		}
		//���Ŀ��
		void addTarget(Vertex *const vertex) {
			if (hasTarget(vertex))
				m_targets.push_back(vertex);
		}
		//ɾ��Ŀ��
		void removeTarget(Vertex *const vertex) {
			auto it = std::find(m_targets.begin(), m_targets.end(), vertex);
			if (it != m_targets.end())
				m_targets.erase(it);
		}

	private:
		EdgeDType m_data; //����
		Vertex *m_from; //��Դ
		VertexVector m_targets; //Ŀ��
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