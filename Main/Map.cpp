
using namespace Main;

Map::Map(int width, int height){
    _width = width;
    _height = height; 
    _map = new ItemModel *[_width];
    
    for (int i = 0; i < _width; i++) {
        _map[i] = new ItemModel[_height];
    }
}

void Map::SetEmptyMap()
{
    for (int i = 0; i < _width; i++) 
    {
        for (int j = 0; j < _height; j++) 
        {
            _map[i][j]=" ";
        }
    }
}

void Map::PrintMap(){
    for (int i = 0; i < _width; i++) 
    {
        for (int j = 0; j < _height; j++) 
        {
            if(_map[i][j].GetType() != null){
                cout << _map[i][j].GetType();
            }else{
                cout << " ";
            }
        }
        cout << "\n"<< endl;
    }
}

void Map::AddItem(int width, int height, ItemModel item)
{
    _map[width][height]=item;
}

void Map::RemoveItem(int x, int y){
    _map[width][height]= nullptr;
}

void Map::SetItemList(){
    for (int i = 0; i < _width; i++) 
    {
        for (int j = 0; j < _height; j++) 
        {
            if(_map[i][j].GetType() != nullptr){
                _itemList.push_back(_map[i][j]);
            }else{
                for (item = _itemList.begin(); item != _itemList.end(); item++)
	        {
                    if(_itemList[item].GetType() == _map[i][j].GetType()){
                        _itemList[item].SetValue(_itemList[item].GetValue() +  _map[i][j].GetValue());
                    }
	        }
            }
        }
    } 
}