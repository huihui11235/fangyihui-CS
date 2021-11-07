void FindComMove(BoardType Board, int *BestMove, int *Value, int Alpha, int Beta) {
	int Dc, i, Response;
	if (FullBoard(Board))				//�ж������Ƿ�����������������ƽ��
		*Value = Draw;
	else if (ImmediateHumanWin(Board))	//�ж������Ƿ�Ӯ
		*Value = ComLoss;
	else {
		*Value = Alpha;
		//����֦���µ�ֵ������ڦ���ֵ�������֦
		for (i = 0; i < 9 && *Value < Beta; i++) {
			if (IsEmpty(Board, i / 3, i % 3)) {
				Place(Board, i / 3, i % 3, 'C');	//����
				FindHumanMove(Board, &Dc, &Response, *Value, Beta);
				//ģ���������壬����������
				Unplace(Board, i / 3, i % 3);		//��������
				if (Response > *Value) {			//��λ�ø��ã������λ��
					*Value = Response;
					*BestMove = i;
				}
			}
		}
	}
}

void FindHumanMove(BoardType Board, int *BestMove, int *Value, int Alpha, int Beta) {
	int Dc, i, Response;
	if (FullBoard(Board))			//�ж������Ƿ�������������ƽ��
		*Value = Draw;
	else if (ImmediateComWin(Board))	//�жϼ�����Ƿ�Ӯ
		*Value = ComWin;
	else {
		*Value = Beta;
		//�¼�֦��������ֵ���ڦ£�����м�֦
		for (i = 0; i < 9 && *Value > Alpha; i++) {
			if (IsEmpty(Board, i / 3, i % 3)) {
				Place(Board, i / 3, i % 3, 'H');	 //����
				FindComMove(Board, &Dc, &Response, Alpha, *Value);
				//ģ���������壬����������
				Unplace(Board, i / 3, i % 3);		//��������
				if (Response < *Value) {
					//���и��õ�λ�ã������
					*Value = Response;
					*BestMove = i;
				}
			}
		}
	}
}