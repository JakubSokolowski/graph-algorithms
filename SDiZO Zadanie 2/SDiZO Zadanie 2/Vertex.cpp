#include "stdafx.h"
#include "Vertex.h"

SDZ::Vertex::Vertex()
	: vertex_id_(0)
	, list_()
	, visited_(false)
	, is_open_(false)
	, is_closed_(false)
	, is_separated(true)
{}

SDZ::Vertex::Vertex(uint id)
	: vertex_id_(id)
	, list_()
	, visited_(false)
	, is_open_(false)
	, is_closed_(false)
{}

SDZ::Vertex::~Vertex()
{}

void SDZ::Vertex::AddEdge(uint destination, uint weight)
{
	Edge new_edge = Edge(vertex_id_, destination, weight);
	list_.PushBack(new_edge);
}

void SDZ::Vertex::DisplayListWithWeights()
{
	std::cout << "Adjacency List for Vertex " << vertex_id_ << std::endl;
	for (auto it = list_.begin(); it != list_.end(); it++)
		std::cout << it->destination_id << "-" << it->weight_ << "  ";
	std::cout << std::endl;
}

void SDZ::Vertex::DisplayList()
{
	std::cout << "Adjacency List for Vertex " << vertex_id_ << std::endl;
	for (auto it = list_.begin(); it != list_.end(); it++)
		std::cout << it->destination_id <<" ";
	std::cout << std::endl;
}

bool SDZ::Vertex::IsConnected(uint destination)
{
	for (auto it = list_.begin(); it != list_.end(); it++)
	{
		if (destination == it->destination_id)
			return true;
	}
	return false;
}

uint SDZ::Vertex::GetConnectionWeight(uint destination)
{
	for (auto it = list_.begin(); it != list_.end(); it++)
	{
		if (destination == it->destination_id)
			return it->weight_;
	}
}

void SDZ::Vertex::SetCoordinates(uint x, uint y)
{
	x_ = x;
	y_ = y;
}

SDZ::Vertex & SDZ::Vertex::operator=(const Vertex &other)
{
	vertex_id_ = other.vertex_id_;
	visited_ = other.visited_;
	list_ = std::move(other.list_);
	return *this;
}

void SDZ::Vertex::UpadatePriority()
{
	
}


