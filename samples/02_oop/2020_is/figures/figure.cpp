#include "figure.h"
#include "ffactory.h"


Figure *Figure::loadFigure(std::istream&in)
{
    std::string type;
    in >> type;
    Figure *newFigure = nullptr;
    try
    {
        newFigure = FigureFactory::make(type);
        newFigure->load(in);
    } 
    catch (const UnknownFigureException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
      
    return newFigure;
}


std::istream& operator >> (std::istream& in, std::vector<Figure*>& figures)
{
    size_t nFigures;
    in >> nFigures;

    figures.clear();

    for (size_t i = 0; i < nFigures; ++i)
    {
        Figure *newFigure = Figure::loadFigure(in);
        if (newFigure != nullptr)
        {
            figures.push_back(newFigure);
        } else 
        {
            return in;
        }

    }
    return in;
}

std::ostream& operator << (std::ostream& out, std::vector<Figure*> figures)
{
    out << figures.size () << " ";
    for (Figure *f : figures)
    {
        f->save(out);
    }
    return out;
}

double Figure::sumSurfaces(std::vector<Figure*> figures)
{
    double sum = 0;
    for (Figure* f : figures)
    {
        sum += f->surface();
    }
    return sum;
}

Figure::~Figure()
{
    
}
