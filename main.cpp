#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>
#include <iterator>
#include <map>
#include <sstream>
#include <ctime>


namespace LADS {
/*
    template <class SizeClass>
    struct Column{
        Column(SizeClass i){ index = i;};
        Column<SizeClass>& operator=(Column<SizeClass>& a){ index = a.index; return *this;};
        SizeClass index;
    };
*/
    template <class BaseClass, class SizeClass>
    class Row{
        std::vector<SizeClass >* columnPermutation;
        BaseClass* base;
        public:
        SizeClass index;
        Row(): base(0), columnPermutation(0) {
        }
        Row(BaseClass* base, std::vector<SizeClass >*  columnPermutation, SizeClass index ){
            this->index = index;
            this->base = base;
            this->columnPermutation = columnPermutation;
        }
        BaseClass& operator[](SizeClass i){
            return base[ columnPermutation -> at(i) ];
            //return base[ (*columnPermutation)[i] ];
        }
    };


    template<class DataClass, class SizeClass>
    class Matrix {

        DataClass** matrix;
        std::vector<SizeClass > columns;
        std::vector<Row<DataClass , SizeClass > > rows;
        public:
        typedef typename std::vector<Row<DataClass ,  SizeClass > >::iterator RowIterator;
        typedef typename std::vector< SizeClass  >::iterator ColumnIterator;
        RowIterator rowBegin(){
            return rows.begin();
        }
        RowIterator rowEnd(){
            return rows.end();
        }
        ColumnIterator columnBegin(){
            return columns.begin();
        }
        ColumnIterator columnEnd(){
            return columns.end();
        }

        Row<DataClass , SizeClass >& operator[](SizeClass i){
            //return rows.at(i);
            return rows[i];
        }

        Matrix(DataClass** a, SizeClass n, SizeClass m) : matrix(a)/*, columns(m), rows(n)*/{
            for(SizeClass i = 0; i < m; ++i) columns.push_back( i );
            for(SizeClass i = 0; i < n; ++i){
                Row<DataClass, SizeClass > row(matrix[i], &columns, i);
                rows.push_back(row);
            }
        }

        void swap_rows(SizeClass a, SizeClass b){
            std::swap(rows.at(a), rows.at(b));
        }
        void swap_columns(SizeClass a, SizeClass b){
            std::swap(columns.at(a), columns.at(b));
        }

        void setRowPermutation(std::vector<SizeClass> permutation ){
            std::vector< Row<DataClass , SizeClass > > temp (rows.size()) ;
            std::copy(rows.begin(), rows.end(), temp.begin());
            RowIterator res = rows.begin();
            typename std::vector<SizeClass>::iterator it = permutation.begin();
            typename std::vector<SizeClass>::iterator end = permutation.end();
            for(; it != end; ++it, ++res) *res = temp.at(*it);
        }

        void setColumnPermutation(std::vector<SizeClass> permutation ){
            std::vector< SizeClass > temp (columns.size()) ;
            std::copy(columns.begin(), columns.end(), temp.begin());
            ColumnIterator res = rows.begin();
            typename std::vector<SizeClass>::iterator it = permutation.begin();
            typename std::vector<SizeClass>::iterator end = permutation.end();
            for(; it != end; ++it, ++res) *res = temp.at(*it);
        }

        DataClass** getInitialMatrix(){
            return matrix;
        }

    };
};


typedef LADS::Matrix<int,int> Mi;
typedef LADS::Matrix<double,int> Md;




int main(){



}
