class TilesSdl : public GameObject {
public:
    Tiles *tiles;
    TilesSdl(double x, double y, double w, double h, int numberInTile);
    double posX() override;
    double posY() override;
    double width() override;
    double height() override;
    void draw(SDL_Renderer* renderer);
    ~TilesSdl() override;

    double getX() const { return x; }
    double getY() const { return y; }

private:
    SDL_Color color;
    TTF_Font* font; // For font management
    double x;
    double y;
    double w;
    double h;
};
