void FindComMove(BoardType Board, int *BestMove, int *Value, int Alpha, int Beta) {
	int Dc, i, Response;
	if (FullBoard(Board))				//判断棋盘是否下满，若下满，则平局
		*Value = Draw;
	else if (ImmediateHumanWin(Board))	//判断人类是否赢
		*Value = ComLoss;
	else {
		*Value = Alpha;
		//α剪枝，β的值必须大于α的值，否则剪枝
		for (i = 0; i < 9 && *Value < Beta; i++) {
			if (IsEmpty(Board, i / 3, i % 3)) {
				Place(Board, i / 3, i % 3, 'C');	//下棋
				FindHumanMove(Board, &Dc, &Response, *Value, Beta);
				//模拟人类下棋，构建博弈树
				Unplace(Board, i / 3, i % 3);		//撤销下棋
				if (Response > *Value) {			//若位置更好，则更新位置
					*Value = Response;
					*BestMove = i;
				}
			}
		}
	}
}

void FindHumanMove(BoardType Board, int *BestMove, int *Value, int Alpha, int Beta) {
	int Dc, i, Response;
	if (FullBoard(Board))			//判断棋盘是否已满，若是则平局
		*Value = Draw;
	else if (ImmediateComWin(Board))	//判断计算机是否赢
		*Value = ComWin;
	else {
		*Value = Beta;
		//β剪枝，若α的值大于β，则进行剪枝
		for (i = 0; i < 9 && *Value > Alpha; i++) {
			if (IsEmpty(Board, i / 3, i % 3)) {
				Place(Board, i / 3, i % 3, 'H');	 //下棋
				FindComMove(Board, &Dc, &Response, Alpha, *Value);
				//模拟计算机下棋，构建博弈树
				Unplace(Board, i / 3, i % 3);		//撤销下棋
				if (Response < *Value) {
					//若有更好的位置，则更新
					*Value = Response;
					*BestMove = i;
				}
			}
		}
	}
}